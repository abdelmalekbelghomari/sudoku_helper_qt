#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QMovie>
#include <QLabel>
#include <QString>
#include <QScreen>
#include <QGuiApplication>

class AnimatedSplashScreen : public QSplashScreen {
    Q_OBJECT
public:
    explicit AnimatedSplashScreen(const QString &fileName = ":/images/haybdel_studios.gif", QWidget *parent = nullptr);
    ~AnimatedSplashScreen();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void updateFrame(const int frameNumber);
private:
    QMovie * _movie;
};

#endif // SPLASHSCREEN_H
