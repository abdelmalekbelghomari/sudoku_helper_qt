#include "BoardFactory.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

// Helper function to load boards from a file
std::vector<std::string> BoardFactory::loadBoards(const std::string& filePath) {
    std::vector<std::string> boards;
    std::ifstream file(filePath);
    std::string line;

    if (file.is_open()) {
        // Skip the first line containing the number of boards
        std::getline(file, line);
        // Read and store all boards
        while (std::getline(file, line)) {
            boards.push_back(line);
        }
        file.close();
    }
    return boards;
}

// Implementation of the BoardFactory to create a board
std::string BoardFactory::createBoard(const std::string& filePath) {
    // Load the boards from the specified file
    std::vector<std::string> boards = loadBoards(filePath);
    
    // Seed the random number generator to ensure different outcomes
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Ensure there are boards to choose from
    if (!boards.empty()) {
        // Select a random board
        int index = std::rand() % boards.size();
        return boards[index];
    }

    // Return an empty string if no boards were loaded
    return "";
}
