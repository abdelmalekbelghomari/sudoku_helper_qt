#ifndef LOADINGGAMESCREEN_H
#define LOADINGGAMESCREEN_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QMovie>
#include <QTimer>
#include <QLabel>

namespace Ui {
class LoadingGameScreen;
}

class LoadingGameScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadingGameScreen(QWidget *parent = nullptr);
    ~LoadingGameScreen();
// private slots:
//     void redirectedHomePage();
// signals:
//     void showHomePage();

private:
    Ui::LoadingGameScreen *ui;
    QString _gifAnimation;
};

#endif // LOADINGGAMESCREEN_H
