#ifndef FIGURESDISPLAYER_H
#define FIGURESDISPLAYER_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>

class FiguresDisplayer : public QWidget {
    Q_OBJECT

public:
    explicit FiguresDisplayer(QWidget *parent = nullptr);

    void setFixedNumber(int number);
    void setEditable(bool editable);

private:
    QLabel *numberLabel;
    QComboBox *numberComboBox;
    QGridLayout *layout;

    void createFixedNumber(int number);
    void createComboBox();
};

#endif // FIGURESDISPLAYER_H
