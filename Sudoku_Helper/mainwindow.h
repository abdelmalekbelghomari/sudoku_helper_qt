#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <QTimer>
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
public slots:
    void solvePuzzleRequest();

private:
    Ui::MainWindow *ui;
    Presenter * _presenter;
    QTimer * _timer;
    QDateTime _startTime;

};
#endif // MAINWINDOW_H
