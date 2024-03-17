#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <QString>


class SudokuSolver
{
public:
    SudokuSolver();
    SudokuSolver(int level, int grid);
    std::vector<std::vector<int>> getPuzzle() const;
    QString solveSudoku(const QString& sudoku);
    bool solve(int grid[9][9], int row, int col);
    bool isSafe(int grid[9][9], int row, int col, int num);
    // ~SudokuSolver();

private:
    int _level; /* 0 for easy
                * 1 for medium
                * 2 for hard
                * 3 for insane */
    int _gridChosen;

    std::vector<std::string> fileNames = {
        "grids/Easy.txt",
        "grids/Medium.txt",
        "grids/Hard.txt",
        "Insane.txt"
    };


    std::vector<std::vector<std::vector<int>>> _puzzles;
    std::vector<std::vector<int>> _sudoku;
    bool loadFromFile(const std::string& fileName);
    bool solveSudoku(std::vector<std::vector<int>>& puzzle);
    void solveAllSudokus();
    bool isValid(int row, int col, int num, const std::vector<std::vector<int>>& puzzle) const;
    bool findEmptyPosition(int& row, int& col, const std::vector<std::vector<int>>& puzzle) const;
    void printSudoku(const std::vector<std::vector<int>>& puzzle) const; //Used for tests
    std::vector<int> getPossibleValues(int row, int col) const ;
};

#endif // SUDOKUSOLVER_H
