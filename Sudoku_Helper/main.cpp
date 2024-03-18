#include "mainwindow.h"
#include "HomePageWindow.h"
#include "LoadingGameScreen.h"
#include "AnimatedSplashScreen.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Sudoku_Helper_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    //SudokuSolver solver(3,2);

    MainWindow w;
    HomePageWindow h;
    LoadingGameScreen l;
    AnimatedSplashScreen splashScreen;
    l.show();
    // splashScreen.show();

    QTimer::singleShot(5000, &a, [&]() {
        l.close();
        h.show();
    });

    QObject::connect(&w, &MainWindow::quitGame, &a, [&](){
        w.close();
    });

    QObject::connect(&h, &HomePageWindow::startNewGame, &a ,[&]() {
        h.pausePlayer();
        h.hide();
        w.show();
    });

    QObject::connect(&w, &MainWindow::showHomePage, &a ,[&]() {
        w.hide();
        h.show();
        h.playPlayer();
    });

    return a.exec();
}
