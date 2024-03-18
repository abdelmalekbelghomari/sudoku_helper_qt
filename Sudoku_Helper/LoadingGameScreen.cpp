#include "LoadingGameScreen.h"
#include "ui_loadinggamescreen.h"

LoadingGameScreen::LoadingGameScreen(QWidget *parent)
    : QMainWindow(parent),  ui(new Ui::LoadingGameScreen), _gifAnimation(":/images/haydel_studio_transparent.gif")
{
    ui->setupUi(this);
    this->setFixedSize(1000, 621);
    this->setWindowTitle("Sudoku - Loading Sreen");

    QMovie *titleAnimation = new QMovie(_gifAnimation);
    ui->studioLabel->setMovie(titleAnimation);
    titleAnimation->start();

    _player = new QMediaPlayer(this);
    _player->setMedia(QUrl("qrc:/musics/Light Stone_Dark Stone.mp3"));
    _player->setVolume(50);
    _player->play();

    if (_player->error() != QMediaPlayer::NoError) {
        qDebug() << "Erreur lors de la configuration de QMediaPlayer :" << _player->errorString();
    } else {
        qDebug() << "QMediaPlayer a été configuré avec succès.";
    }

    if (_player->state() == QMediaPlayer::PlayingState) {
        qDebug() << "La lecture de la musique a commencé avec succès.";
    } else {
        qDebug() << "La lecture de la musique n'a pas pu être démarrée. État actuel :" << _player->state();
    }
    qDebug() << "Volume de lecture réglé à :" << _player->volume();

}

LoadingGameScreen::~LoadingGameScreen()
{
    delete ui;
    delete _player;
}
