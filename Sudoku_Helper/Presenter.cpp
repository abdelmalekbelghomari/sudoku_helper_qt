#include "Presenter.h"
#include "BoardFactory.h" // Assurez-vous d'inclure BoardFactory
#include <QString>
#include <QSet>
Presenter::Presenter(FiguresDisplayer* view, QObject *parent)
    : QObject(parent), _view(view) {}

void Presenter::onStartNewGame(const std::string& level) {
    _view->clear();
    // Spécifiez le chemin vers votre fichier de grilles selon le niveau
    std::string gridPath;
    if (level == "easy") {
        gridPath = "grids/Easy.txt";
    } else if (level == "medium") {
        gridPath = "grids/Medium.txt";
    } else if (level == "hard"){
        gridPath = "grids/Hard.txt";
    }else {
        gridPath = "grids/Insane.txt";    // Ajoutez d'autres niveaux selon vos besoins
    }
    // Utilisez BoardFactory pour obtenir une grille aléatoire
    std::string initialGrid = _factory.createBoard(gridPath);
    // Convertir std::string en QString
    QString qInitialGrid = QString::fromStdString(initialGrid);

    // Appeler setNumbers sur la vue avec la grille initiale
    _view->setNumbers(qInitialGrid);
    _view->filterNumbers();
}

