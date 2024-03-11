#pragma once
#include <string>
#include <vector>


class BoardFactory {
public:
    static std::string createBoard(const std::string& filePath);
private:
    static std::vector<std::string> loadBoards(const std::string& filePath);
};