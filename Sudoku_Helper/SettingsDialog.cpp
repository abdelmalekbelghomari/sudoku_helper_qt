#include "SettingsDialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    setWindowTitle("Settings");
    matchLanguageWithCode();

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::applySettings);
    connect(&ConfigurationManager::instance(), &ConfigurationManager::languageChanged, this, &SettingsDialog::handleTranslation);

}

void SettingsDialog::applySettings() {
    bool musicEnabled = ui->musicCheckBox->isChecked();
    int soundLevel = ui->soundSlider->value();
    int index = ui->languageComboBox->currentIndex();
    QString languageCode = ui->languageComboBox->itemData(index).toString();

    ConfigurationManager::instance().setMusicEnabled(musicEnabled);
    ConfigurationManager::instance().setSoundLevel(soundLevel);
    ConfigurationManager::instance().setLanguage(languageCode);

    accept();
}

void SettingsDialog::matchLanguageWithCode() {
    ui->languageComboBox->setItemData(0, "en_GB");
    ui->languageComboBox->setItemData(1, "fr_FR");
    ui->languageComboBox->setItemData(2, "ja_JP");
    ui->languageComboBox->setItemData(3, "de_DE");
    ui->languageComboBox->setItemData(4, "es_ES");
}

void SettingsDialog::handleTranslation(const QString &language){
    ui->retranslateUi(this);
}


SettingsDialog::~SettingsDialog()
{
    delete ui;
}
