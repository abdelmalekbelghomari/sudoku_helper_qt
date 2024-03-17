/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "FiguresDisplayer.h"
#include "SudokuDrawer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionQuit;
    QAction *actionSolve;
    QAction *actionHome;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    FiguresDisplayer *figureSelector;
    SudokuDrawer *sudokuWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *levelLabel;
    QComboBox *LevelComboBox;
    QComboBox *gridSelectorComboBox;
    QPushButton *newGameButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 621);
        MainWindow->setMinimumSize(QSize(1000, 600));
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-new")));
        actionNew_Game->setIcon(icon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("system-shutdown")));
        actionQuit->setIcon(icon1);
        actionSolve = new QAction(MainWindow);
        actionSolve->setObjectName(QString::fromUtf8("actionSolve"));
        actionHome = new QAction(MainWindow);
        actionHome->setObjectName(QString::fromUtf8("actionHome"));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("go-home")));
        actionHome->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        figureSelector = new FiguresDisplayer(centralwidget);
        figureSelector->setObjectName(QString::fromUtf8("figureSelector"));

        horizontalLayout_2->addWidget(figureSelector);

        sudokuWidget = new SudokuDrawer(centralwidget);
        sudokuWidget->setObjectName(QString::fromUtf8("sudokuWidget"));
        sudokuWidget->setMinimumSize(QSize(500, 500));

        horizontalLayout_2->addWidget(sudokuWidget);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 25, -1, -1);
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        levelLabel = new QLabel(centralwidget);
        levelLabel->setObjectName(QString::fromUtf8("levelLabel"));

        horizontalLayout->addWidget(levelLabel);

        LevelComboBox = new QComboBox(centralwidget);
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("face-smile")));
        LevelComboBox->addItem(icon3, QString());
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("face-cool")));
        LevelComboBox->addItem(icon4, QString());
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("face-devilish")));
        LevelComboBox->addItem(icon5, QString());
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("face-sick")));
        LevelComboBox->addItem(icon6, QString());
        LevelComboBox->setObjectName(QString::fromUtf8("LevelComboBox"));
        LevelComboBox->setMinimumSize(QSize(130, 0));

        horizontalLayout->addWidget(LevelComboBox);

        gridSelectorComboBox = new QComboBox(centralwidget);
        gridSelectorComboBox->addItem(QString());
        gridSelectorComboBox->setObjectName(QString::fromUtf8("gridSelectorComboBox"));

        horizontalLayout->addWidget(gridSelectorComboBox);

        newGameButton = new QPushButton(centralwidget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));

        horizontalLayout->addWidget(newGameButton);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(newGameButton, LevelComboBox);
        QWidget::setTabOrder(LevelComboBox, gridSelectorComboBox);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionNew_Game);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuFile->addAction(actionHome);
        menuOptions->addAction(actionSolve);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sudoku Helper", nullptr));
        actionNew_Game->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Game->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSolve->setText(QCoreApplication::translate("MainWindow", "Solve ", nullptr));
#if QT_CONFIG(shortcut)
        actionSolve->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHome->setText(QCoreApplication::translate("MainWindow", "Home Screen", nullptr));
#if QT_CONFIG(shortcut)
        actionHome->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        levelLabel->setText(QCoreApplication::translate("MainWindow", "Level (Please Select) :", nullptr));
        LevelComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Easy", nullptr));
        LevelComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Medium", "Medium Level"));
        LevelComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Hard", nullptr));
        LevelComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Insane", nullptr));

        gridSelectorComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Random", nullptr));

        newGameButton->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
