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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionQuit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QFrame *line_3;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_4;
    FiguresDisplayer *square1;
    QWidget *square2;
    QWidget *square3;
    QWidget *square4;
    QWidget *square5;
    QWidget *square6;
    QWidget *square7;
    QWidget *square8;
    QWidget *square9;
    QWidget *sudokuWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *levelLabel;
    QComboBox *LevelComboBox;
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
        MainWindow->resize(1248, 789);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 4, 1, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 1);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 4, 3, 1, 1);

        square1 = new FiguresDisplayer(centralwidget);
        square1->setObjectName(QString::fromUtf8("square1"));

        gridLayout->addWidget(square1, 0, 0, 1, 1);

        square2 = new QWidget(centralwidget);
        square2->setObjectName(QString::fromUtf8("square2"));

        gridLayout->addWidget(square2, 0, 2, 1, 1);

        square3 = new QWidget(centralwidget);
        square3->setObjectName(QString::fromUtf8("square3"));

        gridLayout->addWidget(square3, 0, 4, 1, 1);

        square4 = new QWidget(centralwidget);
        square4->setObjectName(QString::fromUtf8("square4"));

        gridLayout->addWidget(square4, 2, 0, 1, 1);

        square5 = new QWidget(centralwidget);
        square5->setObjectName(QString::fromUtf8("square5"));

        gridLayout->addWidget(square5, 2, 2, 1, 1);

        square6 = new QWidget(centralwidget);
        square6->setObjectName(QString::fromUtf8("square6"));

        gridLayout->addWidget(square6, 2, 4, 1, 1);

        square7 = new QWidget(centralwidget);
        square7->setObjectName(QString::fromUtf8("square7"));

        gridLayout->addWidget(square7, 4, 0, 1, 1);

        square8 = new QWidget(centralwidget);
        square8->setObjectName(QString::fromUtf8("square8"));

        gridLayout->addWidget(square8, 4, 2, 1, 1);

        square9 = new QWidget(centralwidget);
        square9->setObjectName(QString::fromUtf8("square9"));

        gridLayout->addWidget(square9, 4, 4, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        sudokuWidget = new QWidget(centralwidget);
        sudokuWidget->setObjectName(QString::fromUtf8("sudokuWidget"));

        horizontalLayout_2->addWidget(sudokuWidget);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 25, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        levelLabel = new QLabel(centralwidget);
        levelLabel->setObjectName(QString::fromUtf8("levelLabel"));

        horizontalLayout->addWidget(levelLabel);

        LevelComboBox = new QComboBox(centralwidget);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("face-smile")));
        LevelComboBox->addItem(icon, QString());
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("face-cool")));
        LevelComboBox->addItem(icon1, QString());
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("face-devilish")));
        LevelComboBox->addItem(icon2, QString());
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("face-sick")));
        LevelComboBox->addItem(icon3, QString());
        LevelComboBox->setObjectName(QString::fromUtf8("LevelComboBox"));

        horizontalLayout->addWidget(LevelComboBox);

        newGameButton = new QPushButton(centralwidget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));

        horizontalLayout->addWidget(newGameButton);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1248, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(newGameButton, LevelComboBox);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionNew_Game);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Game->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        levelLabel->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        LevelComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Easy", nullptr));
        LevelComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Medium", "Medium Level"));
        LevelComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Hard", nullptr));
        LevelComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Insane", nullptr));

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
