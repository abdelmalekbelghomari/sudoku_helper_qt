#include "SudokuSolver.h"
#include <QString>
#include <QDebug>
using namespace std;


// SudokuSolver::SudokuSolver(){
//     loadFromFile(fileNames.at(rand()%4));
// }

SudokuSolver::SudokuSolver(int level, int gridChoice) : _level(level) {
    loadFromFile(fileNames.at(_level));
    _gridChosen = gridChoice;
    _sudoku = _puzzles.at(_gridChosen);
    // printSudoku(_puzzles.at(_gridChose));
    // cout << "\t===== Solving the sudoku ======\n";
    // solveSudoku(_puzzles.at(_gridChose));
    // cout << "\t===== Sudoku Solved ======\n";
    // printSudoku(_puzzles.at(_gridChose));
}

void SudokuSolver::printSudoku(const vector<vector<int>>& puzzle) const {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(puzzle[i][j] == 0) {
                cout << "." << " ";
            } else {
                cout << puzzle[i][j] << " ";
            }
            if(j == 8) cout<<endl;

        }
    }
}

bool SudokuSolver::loadFromFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open file: " << fileName << endl;
        return false;
    }

    int puzzleCount;
    file >> puzzleCount;

    vector<vector<int>> puzzle(9, vector<int>(9));
    string line;
    int index;

    while (getline(file, line)) {
        if (line.length() < 81) {
            continue; // afficher plsu tard la fenetre d'erreur
        }

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                index = i * 9 + j;
                puzzle[i][j] = line[index] - '0';
            }
        }

        _puzzles.push_back(puzzle);
    }

    file.close();
    return true;
}

bool SudokuSolver::isValid(int row, int col, int num, const vector<vector<int>>& puzzle) const {
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == num || puzzle[i][col] == num) return false;

        int regionRow = 3 * (row / 3) + i % 3;
        int regionCol = 3 * (col / 3) + i % 3;
        if (puzzle[regionRow][regionCol] == num) return false;
    }
    return true;
}

bool SudokuSolver::findEmptyPosition(int& row, int& col, const vector<vector<int>>& puzzle) const {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (puzzle[row][col] == 0) return true;
        }
    }
    return false;
}

QString SudokuSolver::solveSudoku(const QString& sudoku) {
    int grid[9][9];
    // Convertir la chaîne d'entrée en grille 2D
    for (int i = 0; i < 81; ++i) {
        grid[i / 9][i % 9] = sudoku[i].digitValue();
    }

    if (solve(grid, 0, 0)) {
        QString solvedSudoku;
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                solvedSudoku.append(QString::number(grid[row][col]));
            }
        }
        return solvedSudoku;
    } else {
        return "No solution";
    }
}

bool SudokuSolver::solve(int grid[9][9], int row, int col) {
    if (row == 9) return true; // Si on a atteint la fin de la grille, le sudoku est résolu
    if (col == 9) return solve(grid, row + 1, 0); // Passer à la ligne suivante

    if (grid[row][col] != 0) return solve(grid, row, col + 1); // Si la cellule n'est pas vide, passer à la suivante

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve(grid, row, col + 1)) return true;

            grid[row][col] = 0; // Backtrack
        }
    }

    return false; // Trigger backtrack
}

bool SudokuSolver::isSafe(int grid[9][9], int row, int col, int num) {
    // Vérifie la ligne
    for (int x = 0; x < 9; ++x)
        if (grid[row][x] == num) return false;

    // Vérifie la colonne
    for (int x = 0; x < 9; ++x)
        if (grid[x][col] == num) return false;

    // Vérifie le carré
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i + startRow][j + startCol] == num) return false;

    return true;
}


// void SudokuSolver::solveAllSudokus() {
//     for (auto& puzzle : _puzzles) {
//         if (solveSudoku(puzzle)) {
//             cout << "Sudoku résolu !" << endl;
//         } else {
//             cout << "Pas de solution trouvée pour un sudoku." << endl;
//         }
//     }
// }

vector<int> SudokuSolver::getPossibleValues(int row, int col) const {
    vector<int> possibleValues;
    vector<bool> present(10, false);
    int value;

    for (int i = 0; i < 9; ++i) {
        value = _puzzles[_level][i][row];
        if (value != 0) {
            present[value] = true;
        }
    }

    for (int i = 0; i < 9; ++i) {
        value = _puzzles[_level][i][col];
        if (value != 0) {
            present[value] = true;
        }
    }

    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (_puzzles[_level][i][j] != 0) {
                present[_puzzles[_level][i][j]] = true;
            }
        }
    }

    for (int i = 1; i <= 9; ++i) {
        if (!present[i]) {
            possibleValues.push_back(i);
        }
    }

    return possibleValues;
}

vector<vector<int>> SudokuSolver::getPuzzle() const{
    return _sudoku;
}


