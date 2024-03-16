#include "Presenter.h"
#include "BoardFactory.h" // Assurez-vous d'inclure BoardFactory
#include "SudokuDrawer.h"
#include <QString>
#include <QSet>
Presenter::Presenter(FiguresDisplayer* view, QObject *parent)
    : QObject(parent), _view(view) {}

void Presenter::onStartNewGame(const std::string& level, int index) {
    _view->clear();

    std::string gridPath;
    if (level == "easy") {
        gridPath = "grids/Easy.txt";
    } else if (level == "medium") {
        gridPath = "grids/Medium.txt";
    } else if (level == "hard") {
        gridPath = "grids/Hard.txt";
    } else {
        gridPath = "grids/Insane.txt";
    }

    std::string initialGrid = _factory.createBoard(gridPath, index);
    QString qInitialGrid = QString::fromStdString(initialGrid);

    _view->setNumbers(qInitialGrid);
    _view->filterNumbers();
    _sudokuDrawer->setFiguresDisplayer(_view);
}


