#ifndef BOARDFACTORY_H
#define BOARDFACTORY_H

#include <string>

class BoardFactory {
public:
    std::string createBoard(const std::string& filePath);
};

#endif // BOARDFACTORY_H