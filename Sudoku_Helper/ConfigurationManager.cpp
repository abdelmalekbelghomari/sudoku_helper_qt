#include "ConfigurationManager.h"

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
    emit languageChanged(language);
}
