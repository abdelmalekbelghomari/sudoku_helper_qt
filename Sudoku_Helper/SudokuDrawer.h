#ifndef SUDOKUDRAWER_H
#define SUDOKUDRAWER_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <QString>
#include <memory>
#include "SudokuSolver.h"

class SudokuDrawer : public QWidget {
    Q_OBJECT

public:
    explicit SudokuDrawer(QWidget *parent = nullptr);
    // ~SudokuDrawer();

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    SudokuSolver * _sudokuSolved;
    std::vector<std::vector<int>> _sudoku;
};

#endif // SUDOKUDRAWER_H
