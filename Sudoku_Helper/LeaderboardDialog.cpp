#include "LeaderboardDialog.h"
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QTableWidget>
#include <QHeaderView>

LeaderboardDialog::LeaderboardDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

    loadAndDisplayData();
}

void LeaderboardDialog::loadAndDisplayData() {
    QFile file("completedLevels.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);

        // Créez la QTableWidget avec 3 colonnes
        QTableWidget* table = new QTableWidget(this);
        table->resize(200, 400);
        table->setColumnCount(3); // Pour Level, Grid, et Time
        table->setHorizontalHeaderLabels({"Level", "Grid", "Time"});
        table->horizontalHeader()->setStretchLastSection(true);
        table->verticalHeader()->setVisible(false);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setSelectionMode(QAbstractItemView::SingleSelection);

        int row = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QRegularExpression re("Level:\\s*(\\w+)\\s*Grid:\\s*(\\d+)\\s*Time:\\s*(\\S+)");
            QRegularExpressionMatch match = re.match(line);
            if (match.hasMatch()) {
                table->insertRow(table->rowCount());
                table->setItem(row, 0, new QTableWidgetItem(match.captured(1)));
                table->setItem(row, 1, new QTableWidgetItem(match.captured(2)));
                table->setItem(row, 2, new QTableWidgetItem(match.captured(3)));
                ++row;
            }
        }

        // Ajuster la taille des colonnes à leur contenu
        table->resizeColumnsToContents();

        // Définissez le layout pour inclure la table
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(table);
        this->setLayout(layout);

        file.close();
    } else {
        // Affiche un message si le fichier ne peut pas être ouvert ou est introuvable
        QLabel *label = new QLabel("No completed levels found.", this);
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        this->setLayout(layout);
    }
}
