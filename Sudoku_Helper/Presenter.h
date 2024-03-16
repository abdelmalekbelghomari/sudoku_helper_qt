#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>
#include "BoardFactory.h" // Assurez-vous que le chemin est correct
#include "FiguresDisplayer.h"

class Presenter : public QObject {
    Q_OBJECT
public:
    Presenter(FiguresDisplayer* view, QObject *parent = nullptr);
    void onStartNewGame(const std::string& level, int index = -1);
    

private:
    FiguresDisplayer* _view;
    BoardFactory _factory;
};

#endif // PRESENTER_H