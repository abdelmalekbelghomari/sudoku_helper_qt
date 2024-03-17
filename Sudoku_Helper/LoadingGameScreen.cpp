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
}

LoadingGameScreen::~LoadingGameScreen()
{
    delete ui;
}
