#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Presenter.h"
#include "FiguresDisplayer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FiguresDisplayer* square = findChild<FiguresDisplayer*>("figureSelector");
    if (square) {
        _presenter = new Presenter(square, this); // Passez `square1` au présentateur
    }

    connect(ui->newGameButton, &QPushButton::clicked, [this]() {
        QString level = ui->LevelComboBox->currentText().toLower();
        _presenter->onStartNewGame(level.toStdString());
    });
}

MainWindow::~MainWindow()
{
    delete _presenter; // Assurez-vous de supprimer le présentateur
    delete ui;
}