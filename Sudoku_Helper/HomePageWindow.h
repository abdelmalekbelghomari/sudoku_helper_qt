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

#include "IWindowInterface.h"
#include "SettingsDialog.h"

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
    void settingsChanged(bool musicEnabled, int soundLevel, QString & language);


private slots:
    void onNewGameClicked();
    void showSettings();
    void handleTranslation(const QString & language);

private:
    Ui::HomePageWindow *ui;
    QMediaPlayer * _musicPlayer;
    QMediaPlaylist * _playlist;
    SettingsDialog * _settingsDialog;
};

#endif // HOMEPAGEWINDOW_H
