#ifndef CHANGEVALUECOMMAND_H
#define CHANGEVALUECOMMAND_H

#include "Command.h"
#include <QString>
#include <QComboBox>

class ChangeValueCommand : public Command {

public:
    ChangeValueCommand(QComboBox* comboBox, const QString& oldValue, const QString& newValue)
        : _comboBox(comboBox), _oldValue(oldValue), _newValue(newValue) {}

    void execute() override;

    void undo() override;
private:
    QComboBox* _comboBox;
    QString _oldValue;
    QString _newValue;
};

#endif // CHANGEVALUECOMMAND_H
