QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AnimatedSplashScreen.cpp \
    BoardFactory.cpp \
    ConfigurationManager.cpp \
    FiguresDisplayer.cpp \
    HomePageWindow.cpp \
    LeaderboardDialog.cpp \
    LoadingGameScreen.cpp \
    LoadingScreen.cpp \
    Presenter.cpp \
    SettingsDialog.cpp \
    SudokuDrawer.cpp \
    SudokuSolver.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AnimatedSplashScreen.h \
    BoardFactory.h \
    ConfigurationManager.h \
    FiguresDisplayer.h \
    HomePageWindow.h \
    IWindowInterface.h \
    LeaderboardDialog.h \
    LoadingGameScreen.h \
    LoadingScreen.h \
    Presenter.h \
    SettingsDialog.h \
    SudokuDrawer.h \
    SudokuSolver.h \
    mainwindow.h

FORMS += \
    homepagewindow.ui \
    loadinggamescreen.ui \
    mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    ressources.qrc


TRANSLATIONS += \
    Sudoku_Helper_en_GB.ts
# CONFIG += lrelease
# CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/binSudoku
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    completedLevels.txt


