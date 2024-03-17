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
}

void HomePageWindow::onNewGameClicked() {
    emit startNewGame();
}

HomePageWindow::~HomePageWindow()
{
    delete ui;
}
