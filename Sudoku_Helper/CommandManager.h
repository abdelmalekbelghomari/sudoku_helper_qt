#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <stack>
#include <memory>
#include "Command.h"
#include <QDebug>

class CommandManager {

public:
    void executeCommand(ChangeValueCommand command);
    void undo();
    void redo();
    int undoStackSize() const;
    int redoStackSize() const;

private:
    std::stack<std::unique_ptr<Command>> _undoStack;
    std::stack<std::unique_ptr<Command>> _redoStack;
};

#endif // COMMANDMANAGER_H
