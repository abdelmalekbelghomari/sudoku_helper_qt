#include "AnimatedSplashScreen.h"

AnimatedSplashScreen::AnimatedSplashScreen(const QString &fileName, QWidget *parent)
    : QSplashScreen(parent), _movie(new QMovie(fileName))
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int width = screenGeometry.width();
    int height = screenGeometry.height();
    int x = (width - this->width()) / 2;
    int y = (height - this->height()) / 2;

    this->move(x, y);
    _movie->setParent(this);
    connect(_movie, &QMovie::frameChanged, this, &AnimatedSplashScreen::updateFrame);
    _movie->start();
}

AnimatedSplashScreen::~AnimatedSplashScreen()
{
    delete _movie;
}

void AnimatedSplashScreen::showEvent(QShowEvent *event)
{
    QSplashScreen::showEvent(event);
    if (_movie && _movie->state() != QMovie::Running)
        _movie->start();
}

void AnimatedSplashScreen::updateFrame(const int /*frameNumber*/)
{
    if (_movie)
        this->setPixmap(_movie->currentPixmap());
}
