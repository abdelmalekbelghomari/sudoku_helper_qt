#ifndef HOMEPAGEWINDOW_H
#define HOMEPAGEWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QMovie>
#include <QTimer>

namespace Ui {
class HomePageWindow;
}

class HomePageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePageWindow(QWidget *parent = nullptr);
    ~HomePageWindow();

signals:
    void startNewGame();

private slots:
    void onNewGameClicked();

private:
    Ui::HomePageWindow *ui;
};

#endif // HOMEPAGEWINDOW_H
