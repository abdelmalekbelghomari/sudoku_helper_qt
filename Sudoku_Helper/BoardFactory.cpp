#include "BoardFactory.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <iostream>

// Unified method to load boards from a file and then create a random board
std::string BoardFactory::createBoard(const std::string& filePath, int index) {
    std::vector<std::string> boards;
    std::ifstream file(filePath);
    std::string line;

    if (file.is_open()) {
        std::getline(file, line); // Skip the first line
        while (std::getline(file, line)) {
            boards.push_back(line);
        }
        file.close();
    }

    if (index != -1 && index < boards.size()) {
        // If an index is specified and is within the range, return that specific board
        return boards[index];
    } else if (!boards.empty()) {
        // Otherwise, return a random board
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int randomIndex = std::rand() % boards.size();
        _randomIndex = randomIndex;
        return boards[randomIndex];
    }
    std::cout << "file not available\n";
    return ""; // Return an empty string if no boards are available or if an invalid index is specified
}

int BoardFactory::getRandomIndex(){
    return _randomIndex;
}
