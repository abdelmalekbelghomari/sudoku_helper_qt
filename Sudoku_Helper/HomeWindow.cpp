#include "HomeWindow.h"

HomeWindow::HomeWindow(QWidget *parent) : QWidget(parent) {
    this->setFixedSize(1000, 621);
    this->setWindowTitle("Sudoku - Accueil");

    newGameButton = new QPushButton("Nouveau Jeu", this);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addStretch(); // Ajoute un espace flexible à gauche du bouton
    hLayout->addWidget(newGameButton); // Ajoute le bouton au layout
    hLayout->addStretch(); // Ajoute un espace flexible à droite du bouton

    // Créer un layout vertical pour centrer le bouton verticalement
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addStretch(); // Ajoute un espace flexible au-dessus du bouton
    vLayout->addLayout(hLayout); // Ajoute le layout horizontal (qui contient le bouton)
    vLayout->addStretch(); // Ajoute un espace flexible en dessous du bouton

    // Appliquer le layout vertical à la fenêtre d'accueil
    setLayout(vLayout);

    // Connecter le signal du bouton au slot correspondant
    connect(newGameButton, &QPushButton::clicked, this, &HomeWindow::onNewGameClicked);
}

void HomeWindow::onNewGameClicked() {
    emit startNewGame();
}
