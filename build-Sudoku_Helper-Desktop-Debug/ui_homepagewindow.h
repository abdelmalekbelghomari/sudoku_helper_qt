/********************************************************************************
** Form generated from reading UI file 'homepagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGEWINDOW_H
#define UI_HOMEPAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePageWindow
{
public:
    QWidget *centralwidget;
    QLabel *backgroundImageLabel;
    QPushButton *newGameButton;
    QLabel *titleLabel;

    void setupUi(QMainWindow *HomePageWindow)
    {
        if (HomePageWindow->objectName().isEmpty())
            HomePageWindow->setObjectName(QString::fromUtf8("HomePageWindow"));
        HomePageWindow->resize(1000, 621);
        HomePageWindow->setMinimumSize(QSize(1000, 621));
        centralwidget = new QWidget(HomePageWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        backgroundImageLabel = new QLabel(centralwidget);
        backgroundImageLabel->setObjectName(QString::fromUtf8("backgroundImageLabel"));
        backgroundImageLabel->setGeometry(QRect(0, 0, 1000, 911));
        backgroundImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/homescreen_background.jpg")));
        newGameButton = new QPushButton(centralwidget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));
        newGameButton->setGeometry(QRect(440, 340, 88, 25));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(170, -120, 661, 391));
        titleLabel->setScaledContents(true);
        titleLabel->setAlignment(Qt::AlignCenter);
        HomePageWindow->setCentralWidget(centralwidget);

        retranslateUi(HomePageWindow);

        QMetaObject::connectSlotsByName(HomePageWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomePageWindow)
    {
        HomePageWindow->setWindowTitle(QCoreApplication::translate("HomePageWindow", "MainWindow", nullptr));
        backgroundImageLabel->setText(QString());
        newGameButton->setText(QCoreApplication::translate("HomePageWindow", "New Game", nullptr));
        titleLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomePageWindow: public Ui_HomePageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGEWINDOW_H
