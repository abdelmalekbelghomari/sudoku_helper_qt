#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
// #include <HomePageWindow.h>
#include "IWindowInterface.h"
#include "ConfigurationManager.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

signals:
    void settingsChanged(bool musicActivated, int soundLevel, QString & language);
private slots:
    void applySettings();
    void handleTranslation(const QString & language);

private:
    Ui::SettingsDialog *ui;
    void matchLanguageWithCode();

};

#endif // SETTINGSDIALOG_H
