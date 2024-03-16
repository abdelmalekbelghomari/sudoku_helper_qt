#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H

#include <string>

class BoardFactory {
public:
    std::string createBoard(const std::string& filePath, int index = -1);
};

#endif // BOARDFACTORY_H