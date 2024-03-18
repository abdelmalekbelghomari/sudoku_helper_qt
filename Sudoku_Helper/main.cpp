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

    MainWindow w;
    HomePageWindow h;
    LoadingGameScreen l;
    AnimatedSplashScreen splashScreen;
    // l.show();
    splashScreen.show();
    h.pausePlayer();
    w.pausePlayer();

    QTimer::singleShot(8000, &a, [&]() {
        // l.show();
        splashScreen.close();
        h.show();
        h.playPlayer();
    });

    QObject::connect(&w, &MainWindow::quitGame, &a, [&](){
        w.close();
    });

    QObject::connect(&h, &HomePageWindow::startNewGame, &a ,[&]() {
        // h.pausePlayer();
        h.hide();
        w.show();
        w.playPlayer();
    });

    QObject::connect(&w, &MainWindow::showHomePage, &a ,[&]() {
        w.pausePlayer();
        w.hide();
        h.show();
        // h.playPlayer();
    });

    return a.exec();
}

// #include "mainwindow.h"
// #include "HomePageWindow.h"
// #include "LoadingGameScreen.h"
// #include "AnimatedSplashScreen.h"

// #include <QApplication>
// #include <QLocale>
// #include <QTranslator>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);

//     QTranslator translator;
//     const QStringList uiLanguages = QLocale::system().uiLanguages();
//     for (const QString &locale : uiLanguages) {
//         const QString baseName = "Sudoku_Helper_" + QLocale(locale).name();
//         if (translator.load(":/i18n/" + baseName)) {
//             a.installTranslator(&translator);
//             break;
//         }
//     }

//     MainWindow w;
//     HomePageWindow h;
//     LoadingGameScreen l;
//     AnimatedSplashScreen splashScreen;

//     // Vérifiez si le premier argument de la ligne de commande est "0"
//     bool useSplashScreen = (argc > 1 && QString(argv[1]) == "0");

//     if (useSplashScreen) {
//         // Affichez l'écran de splash
//         splashScreen.show();

//         // Fermez l'écran de splash et affichez l'écran d'accueil après un certain délai
//         QTimer::singleShot(8000, &a, [&]() {
//             splashScreen.close();
//             h.show();
//             h.playPlayer();
//         });
//     } else {
//         // Affichez l'écran de chargement du jeu
//         l.show();

//         QTimer::singleShot(8000, &a, [&]() {
//             l.close();
//             h.show();
//             h.playPlayer();
//         });

//         // Connectez les signaux et les slots comme d'habitude
//         QObject::connect(&w, &MainWindow::quitGame, &a, [&]() {
//             w.close();
//         });

//         QObject::connect(&h, &HomePageWindow::startNewGame, &a, [&]() {
//             h.hide();
//             w.show();
//             w.playPlayer();
//         });

//         QObject::connect(&w, &MainWindow::showHomePage, &a, [&]() {
//             w.pausePlayer();
//             w.hide();
//             h.show();
//         });
//     }

//     return a.exec();
// }
