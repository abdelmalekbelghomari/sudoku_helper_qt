#include "Presenter.h"
#include "BoardFactory.h" // Assurez-vous d'inclure BoardFactory
#include "SudokuDrawer.h"
#include <QString>
#include <QSet>
Presenter::Presenter(FiguresDisplayer* figuresDisplayer, QObject *parent)
    : QObject(parent), _figuresDisplayer(figuresDisplayer) {}

void Presenter::onStartNewGame(const std::string& level, int index) {
    _figuresDisplayer->clearAll();

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

    _figuresDisplayer->setNumbers(qInitialGrid);
    _figuresDisplayer->filterNumbers();
    _sudokuDrawer->setFiguresDisplayer(_figuresDisplayer);
    if(_factory.getRandomIndex() != -1){
        emit gridSelected( _factory.getRandomIndex());
    }
}


