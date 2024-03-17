#include "LeaderboardDialog.h"
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

LeaderboardDialog::LeaderboardDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

    loadAndDisplayData();
}

void LeaderboardDialog::loadAndDisplayData() {
    QFile file("completedLevels.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString content = in.readAll(); // Lit tout le contenu du fichier d'un coup

        // Affiche le contenu dans un QLabel
        QLabel *label = new QLabel(content, this);
        label->setWordWrap(true); // Permet au texte de passer à la ligne si nécessaire
        layout()->addWidget(label);

        file.close();
    } else {
        // Affiche un message si le fichier ne peut pas être ouvert ou est introuvable
        QLabel *label = new QLabel("No completed levels found.", this);
        layout()->addWidget(label);
    }
}
