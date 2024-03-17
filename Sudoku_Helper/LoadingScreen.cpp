#include "LoadingScreen.h"
// #include "ui_loadingscreen.h"

LoadingScreen::LoadingScreen(QWidget *parent)
    : QMainWindow(parent) /*, ui(new Ui::LoadingScreen)*/
{
    // ui->setupUi(this);
    this->setFixedSize(1000, 621);
    this->setWindowTitle("Sudoku - Loading Sreen");

    _studioLabel = new QLabel(this);
    _studioLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _studioLabel->setAlignment(Qt::AlignCenter);

    QMovie *titleAnimation = new QMovie(_gifAnimation, QByteArray(), this);
    _studioLabel->setMovie(titleAnimation);
    titleAnimation->start();

    setCentralWidget(_studioLabel);

    QTimer::singleShot(5000, this, &LoadingScreen::redirectedHomePage);

}

void LoadingScreen::redirectedHomePage() {
    emit showHomePage();
}

LoadingScreen::~LoadingScreen()
{
    delete _studioLabel;
}
