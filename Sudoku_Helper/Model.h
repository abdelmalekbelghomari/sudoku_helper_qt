#ifndef MODEL_H
#define MODEL_H

include <QObject>
#include <QPoint>

class Model : public QObject {
    Q_OBJECT

public:
    explicit SudokuModel(QObject *parent = nullptr);
    QPoint getWidgetPosition(int row, int col);
};
#endif //MODEL_H