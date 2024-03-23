#include "SettingsDialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::applySettings);

}

void SettingsDialog::applySettings() {
    bool musicEnabled = ui->musicCheckBox->isChecked();
    int soundLevel = ui->soundSlider->value();
    QString language = ui->languageComboBox->currentText();

    ConfigurationManager::instance().setMusicEnabled(musicEnabled);
    ConfigurationManager::instance().setSoundLevel(soundLevel);
    ConfigurationManager::instance().setLanguage(language);

    accept();
}


SettingsDialog::~SettingsDialog()
{
    delete ui;
}
