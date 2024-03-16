#include "SudokuDrawer.h"
#include <QDebug>
#include <QRandomGenerator>
using namespace std;

SudokuDrawer::SudokuDrawer(QWidget *parent) : QWidget(parent) {
    setFixedSize(500, 500); // Example size, adjust as needed
    auto *mainWindow = qobject_cast<MainWindow*>(parent);
    if (mainWindow) {
        connect(mainWindow, &MainWindow::newGameRequested, this, &SudokuDrawer::handleNewGame);
    } else {
        cout << "le bouton newGame est pas connecté\n";
    }
}

void SudokuDrawer::setMainWindow(MainWindow* mainWindow) {
    m_mainWindow = mainWindow;
    if (m_mainWindow) {
        connect(m_mainWindow, &MainWindow::newGameRequested, this, &SudokuDrawer::handleNewGame);
    } else {
        qDebug() << "MainWindow est nulle dans setMainWindow.";
    }
}

void SudokuDrawer::handleNewGame() {
    int difficulty = QRandomGenerator::global()->bounded(0, 4); // Génère un nombre entre 0 et 3 inclus
    int gridNumber = QRandomGenerator::global()->bounded(0, 200); // Génère un nombre entre 0 et 199 inclus

    qDebug() << "handleNewGame appelé avec difficulté" << difficulty << "et grille numéro" << gridNumber;
    _sudokuSolved = new SudokuSolver(difficulty, gridNumber);
    _sudoku = _sudokuSolved->getPuzzle();
    _initialSudoku = _sudoku;
    update(); // Demande de redessiner le widget
}



void SudokuDrawer::updateCell(int row, int col, int newValue) {
    if (row >= 0 && row < 9 && col >= 0 && col < 9) {
        _sudoku[row][col] = newValue;
        update();
    }
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
                painter.eraseRect(i * cellSize + thickLine, j * cellSize + thickLine, cellSize - 2*thickLine, cellSize - 2*thickLine);
                int number = _sudoku[i][j];
                if(number != _initialSudoku[i][j]){
                    painter.setPen(QPen(Qt::blue, lineThickness));
                } else {
                    painter.setPen(QPen(Qt::black, lineThickness));
                }
                painter.drawText(i * cellSize + cellSize / 3, j * cellSize + cellSize / 3 + cellSize/2, QString::number(number));
            }
        }
    }
}

// SudokuDrawer::~SudokuDrawer() {
//     delete _sudokuSolved;
// }
