#ifndef HOMEPAGEWINDOW_H
#define HOMEPAGEWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QMovie>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class HomePageWindow;
}

class HomePageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePageWindow(QWidget *parent = nullptr);
    void pausePlayer();
    void playPlayer();
    ~HomePageWindow();

signals:
    void startNewGame();

private slots:
    void onNewGameClicked();

private:
    Ui::HomePageWindow *ui;
    QMediaPlayer * _musicPlayer;
    QMediaPlaylist * _playlist;
};

#endif // HOMEPAGEWINDOW_H
