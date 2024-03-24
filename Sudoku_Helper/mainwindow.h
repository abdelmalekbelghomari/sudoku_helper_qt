#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QAction>
#include <QActionGroup>
#include <QTranslator>
#include "IWindowInterface.h"
#include "Presenter.h"
#include "LeaderboardDialog.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Presenter;
class QTimer;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showError(const QString &message);
    QString getCurrentTimerTime();
    void updateTimer();


signals:
    void newGameRequested();
    void showHomePage();
    void quitGame();

private slots:
    void on_actionReturnToHomePage();
    void on_actionQuitGame();
    void onLevelChanged(const QString &level);
    void updateCompletedLevels();
    void handleGridSelection(int index);
    void startNewGame();
    void setVolume0();
    void setVolume20();
    void setVolume40();
    void setVolume50();
    void setVolume60();
    void setVolume80();
    void setVolume100();
    void applySettings(bool musicEnabled, int soundLevel, QString language);
    void handleMusicEnabledChanged(bool enabled);
    void handleTranslation(const QString & language);
    void handleSoundLevelChanged(int level);


public slots:

    void solvePuzzleRequest();
    void pausePlayer();
    void playPlayer();
    void playNext();
    void playPrevious();



private:
    Ui::MainWindow *ui;
    Presenter * _presenter;
    QTimer * _timer;
    QDateTime _startTime;
    int _gridIndex;
    QMediaPlayer * _musicPlayer;
    QMediaPlaylist * _playlist;


};
#endif // MAINWINDOW_H
