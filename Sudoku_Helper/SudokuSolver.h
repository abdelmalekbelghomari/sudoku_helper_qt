#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>


class SudokuSolver
{
public:
    SudokuSolver(int level, int grid);

private:
    int _level; /* 0 for easy
                * 1 for medium
                * 2 for hard
                * 3 for insane */

    std::vector<std::string> fileNames = {
        "/home/haykel/interfaces_graphiques/projet/Sudoku_Helper/grids/Easy.txt",
        "path/to/medium_level_puzzles.txt",
        "path/to/hard_level_puzzles.txt",
        "path/to/insane_level_puzzles.txt"
    };


    std::vector<std::vector<std::vector<int>>> _puzzles;
    bool loadFromFile(const std::string& fileName);
    bool solveSudoku(std::vector<std::vector<int>>& puzzle);
    void solveAllSudokus();
    bool isValid(int row, int col, int num, const std::vector<std::vector<int>>& puzzle) const;
    bool findEmptyPosition(int& row, int& col, const std::vector<std::vector<int>>& puzzle) const;
    void print() const; //Used for tests
};

#endif // SUDOKUSOLVER_H
