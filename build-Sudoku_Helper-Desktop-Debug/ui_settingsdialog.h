/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *musicCheckBox;
    QFrame *line;
    QSlider *soundSlider;
    QFrame *line_2;
    QComboBox *languageComboBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(640, 480);
        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 440, 621, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(SettingsDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 130, 621, 201));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(100, 50, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        musicCheckBox = new QCheckBox(horizontalLayoutWidget);
        musicCheckBox->setObjectName(QString::fromUtf8("musicCheckBox"));
        musicCheckBox->setChecked(true);

        verticalLayout->addWidget(musicCheckBox);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        soundSlider = new QSlider(horizontalLayoutWidget);
        soundSlider->setObjectName(QString::fromUtf8("soundSlider"));
        soundSlider->setValue(50);
        soundSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(soundSlider);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        languageComboBox = new QComboBox(horizontalLayoutWidget);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/flags/france.png"), QSize(), QIcon::Normal, QIcon::Off);
        languageComboBox->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/flags/united-kingdom.png"), QSize(), QIcon::Normal, QIcon::Off);
        languageComboBox->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/flags/japan.png"), QSize(), QIcon::Normal, QIcon::Off);
        languageComboBox->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/flags/germany.png"), QSize(), QIcon::Normal, QIcon::Off);
        languageComboBox->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/flags/spain.png"), QSize(), QIcon::Normal, QIcon::Off);
        languageComboBox->addItem(icon4, QString());
        languageComboBox->setObjectName(QString::fromUtf8("languageComboBox"));

        verticalLayout->addWidget(languageComboBox);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(100, 50, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SettingsDialog", "Music :", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsDialog", "Sound Level :", nullptr));
        label_3->setText(QCoreApplication::translate("SettingsDialog", "Language", nullptr));
        musicCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Enabled", nullptr));
        languageComboBox->setItemText(0, QCoreApplication::translate("SettingsDialog", "Fran\303\247ais", nullptr));
        languageComboBox->setItemText(1, QCoreApplication::translate("SettingsDialog", "English", nullptr));
        languageComboBox->setItemText(2, QCoreApplication::translate("SettingsDialog", "\346\227\245\346\234\254\350\252\236", nullptr));
        languageComboBox->setItemText(3, QCoreApplication::translate("SettingsDialog", "Deutsch", nullptr));
        languageComboBox->setItemText(4, QCoreApplication::translate("SettingsDialog", "Espa\303\261ol", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
