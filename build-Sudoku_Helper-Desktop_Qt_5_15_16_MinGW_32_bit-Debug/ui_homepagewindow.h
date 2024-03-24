/********************************************************************************
** Form generated from reading UI file 'homepagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGEWINDOW_H
#define UI_HOMEPAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePageWindow
{
public:
    QWidget *centralwidget;
    QLabel *backgroundImageLabel;
    QPushButton *newGameButton;
    QLabel *titleLabel;
    QToolButton *settingsToolButton;

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
        newGameButton->setGeometry(QRect(430, 334, 111, 31));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(170, -120, 661, 391));
        titleLabel->setScaledContents(true);
        titleLabel->setAlignment(Qt::AlignCenter);
        settingsToolButton = new QToolButton(centralwidget);
        settingsToolButton->setObjectName(QString::fromUtf8("settingsToolButton"));
        settingsToolButton->setGeometry(QRect(870, 510, 111, 101));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/settings_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsToolButton->setIcon(icon);
        settingsToolButton->setIconSize(QSize(120, 120));
        settingsToolButton->setPopupMode(QToolButton::DelayedPopup);
        settingsToolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        settingsToolButton->setAutoRaise(true);
        settingsToolButton->setArrowType(Qt::NoArrow);
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
        settingsToolButton->setText(QCoreApplication::translate("HomePageWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePageWindow: public Ui_HomePageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGEWINDOW_H
