#include "CommandManager.h"
void CommandManager::executeCommand(ChangeValueCommand command) {
    qDebug() << "an action was made!";
    command->execute();
    qDebug() << "command executed";
    _undoStack.push(std::move(command));
    qDebug() << "command pushed";
    while (!_redoStack.empty()) _redoStack.pop(); // Clear redo stack on new command
    qDebug() << "redo stack cleared";
}

void CommandManager::undo() {
    qDebug() << "Undo action";
    if (!_undoStack.empty()) {

        auto command = std::move(_undoStack.top());
        _undoStack.pop();
        command->undo();
        _redoStack.push(std::move(command));
    }else {
        qDebug() << "stack is empty";
    }
}


void CommandManager::redo() {
    if (!_redoStack.empty()) {
        qDebug() << "Redo action";
        auto command = std::move(_redoStack.top());
        _redoStack.pop();
        command->execute();
        _undoStack.push(std::move(command));
    }
}


int CommandManager::undoStackSize() const {
    return _undoStack.size();
}

int CommandManager::redoStackSize() const {
    return _redoStack.size();
}
