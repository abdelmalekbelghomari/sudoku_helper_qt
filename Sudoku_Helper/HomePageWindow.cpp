#include "HomePageWindow.h"
#include "ui_homepagewindow.h"

HomePageWindow::HomePageWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomePageWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000, 621);
    this->setWindowTitle("Sudoku - Accueil");
    QFile file(":/stylesheets/style.qss");
    if(file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "Cannot load stylesheet:" << file.errorString();
    }
    QTimer * timerAnimation = new QTimer(this);
    QMovie * titleAnimation = new QMovie(":/images/sudoku_helper_title.gif");
    ui->titleLabel->setMovie(titleAnimation);
    titleAnimation->start();

    connect(timerAnimation, &QTimer::timeout, this, [titleAnimation, timerAnimation](){
        bool firstTime = true;
        if(firstTime){
            firstTime = false;
            titleAnimation->start();
            timerAnimation->setInterval(6000);
        } else {
            if(titleAnimation->state() == QMovie::Running){
                titleAnimation->stop();
            }
            titleAnimation->start();
        }
    });
    timerAnimation->start(6000);

    connect(ui->newGameButton, &QPushButton::clicked, this, &HomePageWindow::onNewGameClicked);

    _musicPlayer = new QMediaPlayer(this);
    _playlist = new QMediaPlaylist();
    _playlist->addMedia(QUrl("./Pokemon_Center_(Night).mp3"));
    _playlist->addMedia(QUrl("qrc:/musics/Nuvema_Town.mp3"));
    _playlist->addMedia(QUrl("qrc:/musics/Gate.mp3"));
    _playlist->addMedia(QUrl("qrc:/musics/Driftveil_City.mp3"));
    _playlist->setPlaybackMode(QMediaPlaylist::Loop);
    _musicPlayer->setPlaylist(_playlist);
    _musicPlayer->setVolume(50);
    this->playPlayer();

}

void HomePageWindow::pausePlayer(){
    _musicPlayer->pause();
}

void HomePageWindow::playPlayer(){
    _musicPlayer->play();
}

void HomePageWindow::onNewGameClicked() {
    emit startNewGame();
}

HomePageWindow::~HomePageWindow()
{
    delete ui;
    delete _musicPlayer;
}
