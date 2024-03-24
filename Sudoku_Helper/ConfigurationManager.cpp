#include "ConfigurationManager.h"
#include <QDebug>

ConfigurationManager& ConfigurationManager::instance()
{
    static ConfigurationManager _instance;
    return _instance;
}

void ConfigurationManager::setMusicEnabled(bool enabled)
{
    emit musicEnabledChanged(enabled);
}

void ConfigurationManager::setSoundLevel(int level)
{
    emit soundLevelChanged(level);
}

void ConfigurationManager::setLanguage(const QString& language)
{
    static QTranslator translator;
    qApp->removeTranslator(&translator);

    QString translationFilePath = ":/translations/Sudoku_Helper_" + language + ".qm";
    if(translator.load(translationFilePath)) {
        qApp->installTranslator(&translator);
    } else {
        qDebug() << "Failed to load translation file:" << translationFilePath;
    }
    emit languageChanged(language);
}
