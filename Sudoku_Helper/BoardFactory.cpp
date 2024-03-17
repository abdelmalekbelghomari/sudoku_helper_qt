#include "BoardFactory.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <iostream>

// Unified method to load boards from a file and then create a random board
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>

std::string BoardFactory::createBoard(const std::string& filePath, int index) {
    QStringList boards;

    // Charge le fichier à partir des ressources Qt
    QFile file(QString::fromStdString(filePath));

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Impossible d'ouvrir le fichier : " << file.errorString();
        return "";
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        boards << line ;
    }
    file.close();

    if (index != -1 && index < boards.size()) {
        // Si un index est spécifié et est dans la plage, retourner ce tableau spécifique
        return boards[index].toStdString();
    } else if (!boards.isEmpty()) {
        // Sinon, retourner un tableau aléatoire
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int randomIndex = std::rand() % boards.size();
        _randomIndex = randomIndex;
        return boards[randomIndex].toStdString();
    }
    qDebug() << "Fichier non disponible";
    qDebug() << QString::fromStdString(filePath);
    return ""; // Retourne une chaîne vide si aucun tableau n'est disponible ou si un index non valide est spécifié
}


int BoardFactory::getRandomIndex(){
    return _randomIndex;
}
