#ifndef SUDOKUDRAWER_H
#define SUDOKUDRAWER_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <QString>
#include <memory>
#include "SudokuSolver.h"

class FiguresDisplayer;
class MainWindow;
class SudokuDrawer : public QWidget {
    Q_OBJECT

public:
    explicit SudokuDrawer(QWidget *parent = nullptr);
    void setMainWindow(MainWindow* mainWindow);
    void updateSudoku(const QVector<QVector<int>>& sudoku, const QVector<QVector<int>>& initialSudoku);
    void setFiguresDisplayer(FiguresDisplayer* figuresDisplayer);
    void drawGrid(const QString& gridData);
    
    // ~SudokuDrawer();
public slots:
    // void handleNewGame();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    SudokuSolver * _sudokuSolved;
    FiguresDisplayer* _figuresDisplayer;
    void updateCell(int row, int col, int newValue);
    MainWindow* m_mainWindow = nullptr;
};


#endif // SUDOKUDRAWER_H
