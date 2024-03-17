#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sudokuWidget->setMainWindow(this);
    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::handleNewGame);
    connect(ui->actionHome, &QAction::triggered, this, &MainWindow::on_actionReturnToHomePage);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::on_actionQuitGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitGame()
{
    emit quitGame();
}

void MainWindow::handleNewGame(){
    emit newGameRequested();
}

void MainWindow::on_actionReturnToHomePage(){
    emit showHomePage();
}

void MainWindow::showError(const QString &message) {
    QMessageBox::critical(this, tr("Erreur"), message);
}
