#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Presenter.h"
#include "FiguresDisplayer.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FiguresDisplayer* square = findChild<FiguresDisplayer*>("figureSelector");
    if (square) {
        _presenter = new Presenter(square, this); // Passez `square1` au présentateur
    }

    connect(ui->newGameButton, &QPushButton::clicked, [this]() {
    QString level = ui->LevelComboBox->currentText().toLower();
    int gridIndex = ui->gridSelectorComboBox->currentIndex() - 1; // -1 parce que "Random" est la première option
    _presenter->onStartNewGame(level.toStdString(), gridIndex);
});

    connect(ui->LevelComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onLevelChanged(const QString &)));
}

MainWindow::~MainWindow()
{
    delete _presenter; // Assurez-vous de supprimer le présentateur
    delete ui;
}

void MainWindow::onLevelChanged(const QString &level) {
    QString gridPath;
    // Déterminez le chemin du fichier en fonction du niveau sélectionné
    if (level == "Easy") {
        gridPath = "grids/Easy.txt";
    } else if (level == "Medium") {
        gridPath = "grids/Medium.txt";
    } else if (level == "Hard") {
        gridPath = "grids/Hard.txt";
    } else { // Par défaut, supposez "insane"
        gridPath = "grids/Insane.txt";
    }

    ui->gridSelectorComboBox->clear(); // Nettoyez la ComboBox avant d'ajouter de nouveaux items
    ui->gridSelectorComboBox->addItem("Random"); // Ajoutez une option "Random"

    // Ouvrir le fichier pour lire le nombre de grilles disponibles
    QFile file(gridPath);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString line = in.readLine(); // Lire la première ligne qui contient le nombre de grilles
        bool ok;
        int numberOfBoards = line.toInt(&ok);
        if (ok) { // Si la conversion en entier réussit
            // Ajoutez une option pour chaque grille disponible, en commençant à 1
            for (int i = 1; i <= numberOfBoards; i++) {
                ui->gridSelectorComboBox->addItem("Grid " + QString::number(i));
            }
        }
        file.close(); // N'oubliez pas de fermer le fichier
    }
}