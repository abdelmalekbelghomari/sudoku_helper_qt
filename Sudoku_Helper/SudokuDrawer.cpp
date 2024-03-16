#include "SudokuDrawer.h"
using namespace std;

SudokuDrawer::SudokuDrawer(QWidget *parent) : QWidget(parent) {
    setFixedSize(500, 500); // Example size, adjust as needed
    _sudokuSolved = new SudokuSolver(0, 0);
    _sudoku = _sudokuSolved->getPuzzle();
}

void SudokuDrawer::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    const int cellSize = width() / 9;
    const int thickLine = 3;
    const int fineLine = 1;

    QFont font;
    font.setPixelSize(cellSize / 2);
    painter.setFont(font);

    for (int i = 0; i <= 9; ++i) {
        int lineThickness = (i % 3 == 0) ? thickLine : fineLine;
        painter.setPen(QPen(Qt::black, lineThickness));

        painter.drawLine(i * cellSize, 0, i * cellSize, height() - 5);
        painter.drawLine(0, i * cellSize, width() - 5, i * cellSize);

        for (int j = 0; j < 9; ++j) {
            if (_sudoku.size() > i && _sudoku.at(i).size() > j && _sudoku.at(i)[j] != 0) {
                int number = _sudoku[i][j];
                painter.drawText(i * cellSize + cellSize / 3, j * cellSize + cellSize / 3 + cellSize/2, QString::number(number));
            }
        }
    }
}

// SudokuDrawer::~SudokuDrawer() {
//     delete _sudokuSolved;
// }
