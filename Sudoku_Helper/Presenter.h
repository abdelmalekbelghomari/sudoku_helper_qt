#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>
#include <vector>
#include <QString>
#include "BoardFactory.h" // Assurez-vous que le chemin est correct
#include "FiguresDisplayer.h"

class SudokuSolver;
class SudokuDrawer;
class Presenter : public QObject {
    Q_OBJECT
public:
    Presenter(FiguresDisplayer* figuresDisplayer, QObject *parent = nullptr);
    void onStartNewGame(const std::string& level, int index = -1);
    void onSolvePuzzle();
    void handleDrawRequest(const QString& gridData);

private:
    FiguresDisplayer* _figuresDisplayer;
    BoardFactory _factory;
    SudokuDrawer* _sudokuDrawer;
    SudokuSolver* _solver;
    QString _qInitialGrid;

signals:
    void gridSelected(int index);
    
};

#endif // PRESENTER_H
