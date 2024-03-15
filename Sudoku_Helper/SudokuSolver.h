#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>


class SudokuSolver
{
public:
    SudokuSolver();
    SudokuSolver(int level, int grid);
    std::vector<std::vector<int>> getPuzzle();
    // ~SudokuSolver();

private:
    int _level; /* 0 for easy
                * 1 for medium
                * 2 for hard
                * 3 for insane */
    int _gridChose;

    std::vector<std::string> fileNames = {
        "/home/vbdel/Desktop/ENSI/2024/Interfaces_Graph/sudoku helper/Sudoku_Helper/grids/Easy.txt",
        "/home/vbdel/Desktop/ENSI/2024/Interfaces_Graph/sudoku helper/Sudoku_Helper/grids/Medium.txt",
        "/home/vbdel/Desktop/ENSI/2024/Interfaces_Graph/sudoku helper/Sudoku_Helper/grids/Hard.txt",
        "/home/vbdel/Desktop/ENSI/2024/Interfaces_Graph/sudoku helper/Sudoku_Helper/grids/Insane.txt"
    };


    std::vector<std::vector<std::vector<int>>> _puzzles;
    bool loadFromFile(const std::string& fileName);
    bool solveSudoku(std::vector<std::vector<int>>& puzzle);
    void solveAllSudokus();
    bool isValid(int row, int col, int num, const std::vector<std::vector<int>>& puzzle) const;
    bool findEmptyPosition(int& row, int& col, const std::vector<std::vector<int>>& puzzle) const;
    void printSudoku(const std::vector<std::vector<int>>& puzzle) const; //Used for tests
    std::vector<int> getPossibleValues(int row, int col) const ;
};

#endif // SUDOKUSOLVER_H
