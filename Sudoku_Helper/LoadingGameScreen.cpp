#include "LoadingGameScreen.h"
#include "ui_loadinggamescreen.h"

LoadingGameScreen::LoadingGameScreen(QWidget *parent)
    : QMainWindow(parent),  ui(new Ui::LoadingGameScreen), _gifAnimation(":/images/haydel_studios_written.gif")
{
    ui->setupUi(this);
    this->setFixedSize(1000, 621);
    this->setWindowTitle("Sudoku - Loading Sreen");

    QMovie *titleAnimation = new QMovie(_gifAnimation);
    ui->studioLabel->setMovie(titleAnimation);
    titleAnimation->start();

    // QTimer::singleShot(5000, this, &LoadingGameScreen::redirectedHomePage);

}

// void LoadingGameScreen::redirectedHomePage() {
//     emit showHomePage();
// }

LoadingGameScreen::~LoadingGameScreen()
{
    delete ui;
}
