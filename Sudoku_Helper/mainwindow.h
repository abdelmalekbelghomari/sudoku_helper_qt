#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    void handleNewGame();
    void on_actionReturnToHomePage();
    void on_actionQuitGame();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
