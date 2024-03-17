#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "Presenter.h"

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
};
#endif // MAINWINDOW_H
