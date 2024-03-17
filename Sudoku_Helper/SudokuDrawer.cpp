#include "SudokuDrawer.h"
#include <QDebug>
#include <QRandomGenerator>
#include "mainwindow.h"
#include "FiguresDisplayer.h"
using namespace std;

SudokuDrawer::SudokuDrawer(QWidget *parent) : QWidget(parent) {
    setFixedSize(500, 500); // Example size, adjust as needed
}


void SudokuDrawer::setFiguresDisplayer(FiguresDisplayer* figuresDisplayer) {
    _figuresDisplayer = figuresDisplayer;
}

void SudokuDrawer::drawGrid(const QString& gridData) {
    // Stocker gridData et marquer le widget pour redessin
    // this->_gridData = gridData; // Assurez-vous d'avoir un membre _gridData pour stocker ces données
    this->update(); // Provoque le redessin
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

    // Dessinez la grille
    for (int i = 0; i <= 9; ++i) {
        int lineThickness = (i % 3 == 0) ? thickLine : fineLine;
        painter.setPen(QPen(Qt::black, lineThickness));
        painter.drawLine(i * cellSize, 0, i * cellSize, height() - 5);
        painter.drawLine(0, i * cellSize, width() - 5, i * cellSize);
    }

    if (!_figuresDisplayer) return;

    // Parcourir les widgets de _figuresDisplayer pour dessiner les chiffres
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            QWidget* widget = _figuresDisplayer->widgetAt(row, col);
            QString text;
            // Déterminez si c'est un label (état initial) ou un comboBox (choix de l'utilisateur)
            if (auto* label = qobject_cast<QLabel*>(widget)) {
                text = label->text();
                painter.setPen(QPen(Qt::black)); // Utilisez le noir pour l'état initial
            } else if (auto* comboBox = qobject_cast<QComboBox*>(widget)) {
                text = comboBox->currentText();
                if (comboBox->currentIndex() != 0) { // Assurez-vous que ce n'est pas l'item vide
                    painter.setPen(QPen(Qt::blue)); // Utilisez le bleu pour les choix de l'utilisateur
                }
            }

            if (!text.isEmpty() && text != "0") {
                painter.drawText(col * cellSize + cellSize / 3, row * cellSize + 2*cellSize / 3, text);
            }
        }
    }
}

SudokuDrawer::~SudokuDrawer() {
    delete _sudokuSolved;
}
