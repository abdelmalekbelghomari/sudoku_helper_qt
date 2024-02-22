#ifndef SUDOKUDRAWER_H
#define SUDOKUDRAWER_H

#include <QWidget>
#include <QPainter>

class SudokuDrawer : public QWidget {
    Q_OBJECT

public:
    explicit SudokuDrawer(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // SUDOKUDRAWER_H
