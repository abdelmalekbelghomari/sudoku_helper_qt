#include "ChangeValueCommand.h"


void ChangeValueCommand::execute() {
    _comboBox->setCurrentText(_newValue);
}

void ChangeValueCommand::undo() {
    _comboBox->setCurrentText(_oldValue);
}
