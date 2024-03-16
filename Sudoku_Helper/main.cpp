#include "mainwindow.h"
#include "SudokuSolver.h"
#include "HomeWindow.h"

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
    HomeWindow h;
    QObject::connect(&h, &HomeWindow::startNewGame, [&]() {
        h.hide();
        w.show();
    });

    QObject::connect(&w, &MainWindow::showHomePage, [&]() {
        w.hide();
        h.show();
    });


    h.show();
    return a.exec();
}
