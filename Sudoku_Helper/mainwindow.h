#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SudokuDrawer.h"
#include <QDateTime>

class Presenter;
class QTimer;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showError(const QString &message);
    void updateTimer();
    QString getCurrentTimerTime();
 
private:
    Ui::MainWindow *ui;
    Presenter* _presenter;
    QTimer * _timer;
    QDateTime _startTime;


private slots:
    void onLevelChanged(const QString &level);
    void updateCompletedLevels();
    void handleGridSelection(int index);
public slots:
    void solvePuzzleRequest();
    
};
#endif // MAINWINDOW_H
