#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Presenter.h"
#include "FiguresDisplayer.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionHome, &QAction::triggered, this, &MainWindow::on_actionReturnToHomePage);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::on_actionQuitGame);

    FiguresDisplayer* square = findChild<FiguresDisplayer*>("figureSelector");
    SudokuDrawer* drawer = findChild<SudokuDrawer*>("sudokuWidget"); // Assurez-vous que l'objectName de SudokuDrawer est correctement défini dans Designer ou dans le code

    if (square && drawer) {
        _presenter = new Presenter(square, this);
        square->setSudokuDrawer(drawer);
        drawer->setFiguresDisplayer(square);
    }



    connect(ui->newGameButton, &QPushButton::clicked,this , [&]() {
        startNewGame();

    });

    connect(ui->actionNew_Game, &QAction::triggered, this, &MainWindow::startNewGame);

    connect(ui->LevelComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onLevelChanged(const QString &)));

    connect(square, &FiguresDisplayer::gameIsCompleted, this, &MainWindow::updateCompletedLevels);

    connect(_presenter, &Presenter::gridSelected, this, &MainWindow::handleGridSelection);

    connect(ui->actionSolve, &QAction::triggered, this, &MainWindow::solvePuzzleRequest);

    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &MainWindow::updateTimer);

    connect(ui->actionLeaderBoard, &QAction::triggered, this,[&]() {
    LeaderboardDialog *dialog = new LeaderboardDialog(this);
    dialog->setWindowTitle("Leaderboard");
    dialog->resize(400, 400);
    dialog->exec();});

    _musicPlayer = new QMediaPlayer(this);
    _playlist = new QMediaPlaylist();
    _playlist->addMedia(QUrl("qrc:/musics/Driftveil_City.mp3"));
    _playlist->addMedia(QUrl("./Pokemon_Center_(Night).mp3"));
    _playlist->addMedia(QUrl("qrc:/musics/Nuvema_Town.mp3"));
    _playlist->addMedia(QUrl("qrc:/musics/Gate.mp3"));

    _playlist->setPlaybackMode(QMediaPlaylist::Loop);
    _musicPlayer->setPlaylist(_playlist);
    _musicPlayer->setVolume(50);
    this->playPlayer();

    connect(ui->actionPlay, &QAction::triggered, this, &MainWindow::playPlayer);
    connect(ui->actionPause, &QAction::triggered, this, &MainWindow::pausePlayer);



    QAction *actionVolume0 = new QAction("0%", this);
    QAction *actionVolume20 = new QAction("20%", this);
    QAction *actionVolume40 = new QAction("40%", this);
    QAction *actionVolume50 = new QAction("50%", this);
    QAction *actionVolume60 = new QAction("60%", this);
    QAction *actionVolume80 = new QAction("80%", this);
    QAction *actionVolume100 = new QAction("100%", this);

    actionVolume0->setCheckable(true);
    actionVolume20->setCheckable(true);
    actionVolume40->setCheckable(true);
    actionVolume50->setCheckable(true);
    actionVolume60->setCheckable(true);
    actionVolume80->setCheckable(true);
    actionVolume100->setCheckable(true);

    QActionGroup *volumeActionGroup = new QActionGroup(this);
    volumeActionGroup->setExclusive(true);

    volumeActionGroup->addAction(actionVolume0);
    volumeActionGroup->addAction(actionVolume20);
    volumeActionGroup->addAction(actionVolume40);
    volumeActionGroup->addAction(actionVolume50);
    volumeActionGroup->addAction(actionVolume60);
    volumeActionGroup->addAction(actionVolume80);
    volumeActionGroup->addAction(actionVolume100);

    ui->menuVolume->addAction(actionVolume0);
    ui->menuVolume->addAction(actionVolume20);
    ui->menuVolume->addAction(actionVolume40);
    ui->menuVolume->addAction(actionVolume50);
    ui->menuVolume->addAction(actionVolume60);
    ui->menuVolume->addAction(actionVolume80);
    ui->menuVolume->addAction(actionVolume100);

    ui->menuVolume->setDefaultAction(actionVolume50);

    connect(actionVolume0, &QAction::triggered, this, &MainWindow::setVolume0);
    connect(actionVolume20, &QAction::triggered, this, &MainWindow::setVolume20);
    connect(actionVolume40, &QAction::triggered, this, &MainWindow::setVolume40);
    connect(actionVolume50, &QAction::triggered, this, &MainWindow::setVolume50);
    connect(actionVolume60, &QAction::triggered, this, &MainWindow::setVolume60);
    connect(actionVolume80, &QAction::triggered, this, &MainWindow::setVolume80);
    connect(actionVolume100, &QAction::triggered, this, &MainWindow::setVolume100);


    connect(ui->actionNext, &QAction::triggered, this, &MainWindow::playNext);
    connect(ui->actionPrevious, &QAction::triggered, this, &MainWindow::playPrevious);



}

void MainWindow::pausePlayer(){
    _musicPlayer->pause();
}

void MainWindow::playPlayer(){
    _musicPlayer->play();
}

void MainWindow::startNewGame(){
    QString level = ui->LevelComboBox->currentText().toLower();
    int _gridIndex = ui->gridSelectorComboBox->currentIndex() - 1; // -1 parce que "Random" est la première option
    _presenter->onStartNewGame(level.toStdString(), _gridIndex);
    _gridIndex++;
    _startTime = QDateTime::currentDateTime();
    _timer->start(1000);
};

MainWindow::~MainWindow()
{
    delete _presenter; // Assurez-vous de supprimer le présentateur
    delete ui;
    delete _timer;
}

void MainWindow::playNext(){
    _playlist->next();
}

void MainWindow::playPrevious(){
    _playlist->previous();
    _playlist->previous();
}

void MainWindow::handleGridSelection(int index) {
    ui->gridSelectorComboBox->setCurrentIndex(index + 1);
}

void MainWindow::onLevelChanged(const QString &level) {
    QString gridPath;
    // Déterminez le chemin du fichier en fonction du niveau sélectionné
    if (level == "Easy") {
        gridPath = ":/grids/Easy.txt";
    } else if (level == "Medium") {
        gridPath = ":/grids/Medium.txt";
    } else if (level == "Hard") {
        gridPath = ":/grids/Hard.txt";
    } else { // Par défaut, supposez "insane"
        gridPath = ":/grids/Insane.txt";
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

void MainWindow::updateTimer() {
    int elapsedSeconds = _startTime.secsTo(QDateTime::currentDateTime());
    QTime time = QTime(0, 0).addSecs(elapsedSeconds);
    ui->timerLabel->setText(time.toString("mm:ss"));
}



void MainWindow::on_actionQuitGame()
{
    emit quitGame();
}
void MainWindow::on_actionReturnToHomePage(){
    emit showHomePage();
}
void MainWindow::showError(const QString &message) {
    QMessageBox::critical(this, tr("Erreur"), message);
}

void MainWindow::solvePuzzleRequest() {
    // Appeler la méthode de résolution dans le présentateur
    if (_presenter) {
        _presenter->onSolvePuzzle();
    }
}

void MainWindow::setVolume0() {
    _musicPlayer->setVolume(0);
}

void MainWindow::setVolume20() {
    _musicPlayer->setVolume(20);
}

void MainWindow::setVolume40() {
    _musicPlayer->setVolume(40);
}

void MainWindow::setVolume50() {
    _musicPlayer->setVolume(50);
}

void MainWindow::setVolume60() {
    _musicPlayer->setVolume(60);
}

void MainWindow::setVolume80() {
    _musicPlayer->setVolume(80);
}

void MainWindow::setVolume100() {
    _musicPlayer->setVolume(100);
}

