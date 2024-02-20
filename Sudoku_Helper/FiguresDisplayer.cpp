#include "FiguresDisplayer.h"

FiguresDisplayer::FiguresDisplayer(QWidget *parent) : QWidget(parent),
    numberLabel(nullptr), numberComboBox(nullptr), layout(new QGridLayout(this)) {
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

void FiguresDisplayer::setFixedNumber(int number) {
    if (numberComboBox) {
        numberComboBox->hide();
        layout->removeWidget(numberComboBox);
        delete numberComboBox;
        numberComboBox = nullptr;
    }

    createFixedNumber(number);
}

void FiguresDisplayer::setEditable(bool editable) {
    if (!editable) {
        if (numberComboBox) {
            numberComboBox->hide();
            layout->removeWidget(numberComboBox);
            delete numberComboBox;
            numberComboBox = nullptr;
        }
        return;
    }

    if (numberLabel) {
        numberLabel->hide();
        layout->removeWidget(numberLabel);
        delete numberLabel;
        numberLabel = nullptr;
    }

    createComboBox();
}

void FiguresDisplayer::createFixedNumber(int number) {
    numberLabel = new QLabel(QString::number(number), this);
    numberLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(numberLabel, 0, 0);
}

void FiguresDisplayer::createComboBox() {
    numberComboBox = new QComboBox(this);
    numberComboBox->addItem(""); // Add an empty item for the user to select if they wish to clear the cell
    for (int i = 1; i <= 9; ++i) {
        numberComboBox->addItem(QString::number(i));
    }
    layout->addWidget(numberComboBox, 0, 0);
}
