#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QMovie>
#include <QTimer>
#include <QLabel>

// namespace Ui {
//     class LoadingScreen;
// }

class LoadingScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadingScreen(QWidget *parent = nullptr);
    ~LoadingScreen();
private slots:
    void redirectedHomePage();
signals:
    void showHomePage();

private:
    // Ui::LoadingScreen *ui;
    QLabel * _studioLabel;
    QString _gifAnimation = ":/images/haybdel_studios.gif";
};

#endif // LOADINGSCREEN_H

