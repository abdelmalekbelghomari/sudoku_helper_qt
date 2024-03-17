#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Presenter.h"
#include "FiguresDisplayer.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <QTimer>    
#include "LeaderboardDialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FiguresDisplayer* square = findChild<FiguresDisplayer*>("figureSelector");
    SudokuDrawer* drawer = findChild<SudokuDrawer*>("sudokuWidget"); // Assurez-vous que l'objectName de SudokuDrawer est correctement défini dans Designer ou dans le code

if (square && drawer) {
    _presenter = new Presenter(square, this);
    square->setSudokuDrawer(drawer);
    drawer->setFiguresDisplayer(square);
}

    

    connect(ui->newGameButton, &QPushButton::clicked, [this]() {
    QString level = ui->LevelComboBox->currentText().toLower();
    int gridIndex = ui->gridSelectorComboBox->currentIndex() - 1; // -1 parce que "Random" est la première option
    _presenter->onStartNewGame(level.toStdString(), gridIndex);
    _startTime = QDateTime::currentDateTime();
    _timer->start(1000);
});

    connect(ui->LevelComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onLevelChanged(const QString &)));

    connect(square, &FiguresDisplayer::gameIsCompleted, this, &MainWindow::updateCompletedLevels);

    connect(_presenter, &Presenter::gridSelected, this, &MainWindow::handleGridSelection);

    connect(ui->actionSolve, &QAction::triggered, this, &MainWindow::solvePuzzleRequest);

    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &MainWindow::updateTimer);

    connect(ui->actionLeaderBoard, &QAction::triggered, [this]() {
    LeaderboardDialog *dialog = new LeaderboardDialog(this);
    dialog->setWindowTitle("Leaderboard");
    dialog->resize(400, 400);
    dialog->exec(); // Ouvre le dialogue en modal
});

}

MainWindow::~MainWindow()
{
    delete _presenter; // Assurez-vous de supprimer le présentateur
    delete ui;
}


void MainWindow::handleGridSelection(int index) {
    ui->gridSelectorComboBox->setCurrentIndex(index + 1);
}

void MainWindow::onLevelChanged(const QString &level) {
    QString gridPath;
    // Déterminez le chemin du fichier en fonction du niveau sélectionné
    if (level == "Easy") {
        gridPath = "grids/Easy.txt";
    } else if (level == "Medium") {
        gridPath = "grids/Medium.txt";
    } else if (level == "Hard") {
        gridPath = "grids/Hard.txt";
    } else { // Par défaut, supposez "insane"
        gridPath = "grids/Insane.txt";
    }

    ui->gridSelectorComboBox->clear(); // Nettoyez la ComboBox avant d'ajouter de nouveaux items
    ui->gridSelectorComboBox->addItem("Random"); // Ajoutez une option "Random"

    QSet<QString> completedLevels;
    QFile prefFile("completedLevels.txt");
    if (prefFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&prefFile);
        QString line;
        while (!in.atEnd()) {
            line = in.readLine();
            completedLevels.insert(line);
        }
        prefFile.close();
    }

    // Ouvrir le fichier pour lire le nombre de grilles disponibles
    QFile file(gridPath);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString line = in.readLine(); // Lire la première ligne qui contient le nombre de grilles
        bool ok;
        int numberOfBoards = line.toInt(&ok);
        if (ok) { // Si la conversion en entier réussit
            // Ajoutez une option pour chaque grille disponible, en commençant à 1
            for (int i = 1; i <= numberOfBoards; i++) {
                QString itemText = "Grid" + QString::number(i);
                ui->gridSelectorComboBox->addItem(itemText);
            }
        }
        file.close(); // N'oubliez pas de fermer le fichier
    }
    
}

void MainWindow::updateCompletedLevels() {
    if (_timer && _timer->isActive()) {
        _timer->stop();
    }

    QString level = ui->LevelComboBox->currentText().toLower();
    int gridIndex = ui->gridSelectorComboBox->currentIndex(); // Assume "Random" is excluded from the count
    QString time = getCurrentTimerTime();

    QString preferencesFilePath = "completedLevels.txt";
    QFile file(preferencesFilePath);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << qSetFieldWidth(10) << left << "Level: " << level 
        << qSetFieldWidth(8) << "Grid: " << gridIndex 
        << qSetFieldWidth(2) << "Time: " << time << "\n";
        file.close();
    }
}
QString MainWindow::getCurrentTimerTime() {
    int elapsedSeconds = _startTime.secsTo(QDateTime::currentDateTime());
    QTime time = QTime(0, 0).addSecs(elapsedSeconds);
    return time.toString("hh:mm:ss");
}

void MainWindow::solvePuzzleRequest() {
    // Appeler la méthode de résolution dans le présentateur
    if (_presenter) {
        _presenter->onSolvePuzzle();
    }
}

void MainWindow::updateTimer() {
    int elapsedSeconds = _startTime.secsTo(QDateTime::currentDateTime());
    QTime time = QTime(0, 0).addSecs(elapsedSeconds);
    ui->timerLabel->setText(time.toString("mm:ss"));
}