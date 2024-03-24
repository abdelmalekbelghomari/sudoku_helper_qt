/********************************************************************************
** Form generated from reading UI file 'loadinggamescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGGAMESCREEN_H
#define UI_LOADINGGAMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingGameScreen
{
public:
    QWidget *centralwidget;
    QLabel *studioLabel;

    void setupUi(QMainWindow *LoadingGameScreen)
    {
        if (LoadingGameScreen->objectName().isEmpty())
            LoadingGameScreen->setObjectName(QString::fromUtf8("LoadingGameScreen"));
        LoadingGameScreen->resize(1000, 621);
        LoadingGameScreen->setMinimumSize(QSize(1000, 621));
        LoadingGameScreen->setMaximumSize(QSize(1000, 621));
        LoadingGameScreen->setStyleSheet(QString::fromUtf8("background-color: black;"));
        centralwidget = new QWidget(LoadingGameScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        studioLabel = new QLabel(centralwidget);
        studioLabel->setObjectName(QString::fromUtf8("studioLabel"));
        studioLabel->setGeometry(QRect(0, 0, 1000, 621));
        studioLabel->setScaledContents(true);
        studioLabel->setAlignment(Qt::AlignCenter);
        LoadingGameScreen->setCentralWidget(centralwidget);

        retranslateUi(LoadingGameScreen);

        QMetaObject::connectSlotsByName(LoadingGameScreen);
    } // setupUi

    void retranslateUi(QMainWindow *LoadingGameScreen)
    {
        LoadingGameScreen->setWindowTitle(QCoreApplication::translate("LoadingGameScreen", "MainWindow", nullptr));
        studioLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoadingGameScreen: public Ui_LoadingGameScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGGAMESCREEN_H
