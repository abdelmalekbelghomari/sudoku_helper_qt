#include "SudokuDrawer.h"

SudokuDrawer::SudokuDrawer(QWidget *parent) : QWidget(parent) {
    setFixedSize(500, 500); // Example size, adjust as needed
}

void SudokuDrawer::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    const int cellSize = width() / 9;
    const int thickLine = 3;
    const int fineLine = 1;

    for (int i = 0; i <= 9; ++i) {

        int lineThickness = (i % 3 == 0) ? thickLine : fineLine;
        painter.setPen(QPen(Qt::black, lineThickness));

        painter.drawLine(i * cellSize, 0, i * cellSize, height()-5);
        painter.drawLine(0, i * cellSize, width()-5, i * cellSize);
    }

}
