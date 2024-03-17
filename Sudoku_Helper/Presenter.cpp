#include "Presenter.h"
#include "BoardFactory.h"
#include "SudokuDrawer.h"
#include "SudokuSolver.h"

Presenter::Presenter(FiguresDisplayer* figuresDisplayer, QObject *parent)
    : QObject(parent), _figuresDisplayer(figuresDisplayer) {}

void Presenter::onStartNewGame(const std::string& level, int index) {
    _figuresDisplayer->clearAll();

    std::string gridPath;
    if (level == "easy") {
        gridPath = ":/grids/Easy.txt";
    } else if (level == "medium") {
        gridPath = ":/grids/Medium.txt";
    } else if (level == "hard") {
        gridPath = ":/grids/Hard.txt";
    } else {
        gridPath = ":/grids/Insane.txt";
    }

    std::string initialGrid = _factory.createBoard(gridPath, index);
    _qInitialGrid = QString::fromStdString(initialGrid);
    _figuresDisplayer->setNumbers(_qInitialGrid);
    _figuresDisplayer->filterNumbers();
    if(_factory.getRandomIndex() != -1){
        emit gridSelected( _factory.getRandomIndex());
    }
}

void Presenter::onSolvePuzzle() {
    QString solution =_solver->solveSudoku(_qInitialGrid);
    _figuresDisplayer->setSolution(solution);
}

void Presenter::handleDrawRequest(const QString& gridData) {
    _sudokuDrawer->drawGrid(gridData);
}


