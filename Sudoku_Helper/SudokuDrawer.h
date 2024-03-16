#ifndef SUDOKUDRAWER_H
#define SUDOKUDRAWER_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <QString>
#include <memory>
#include "SudokuSolver.h"
#include "mainwindow.h"

class SudokuDrawer : public QWidget {
    Q_OBJECT

public:
    explicit SudokuDrawer(QWidget *parent = nullptr);
    void setMainWindow(MainWindow* mainWindow);
    // ~SudokuDrawer();
public slots:
    void handleNewGame();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    SudokuSolver * _sudokuSolved;
    std::vector<std::vector<int>> _sudoku, _initialSudoku;
    void updateCell(int row, int col, int newValue);
    MainWindow* m_mainWindow = nullptr;
};

#endif // SUDOKUDRAWER_H
