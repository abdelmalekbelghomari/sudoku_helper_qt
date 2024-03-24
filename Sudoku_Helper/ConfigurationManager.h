#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include <QObject>
#include <QTranslator>
#include <QApplication>

class ConfigurationManager : public QObject
{
    Q_OBJECT

public:
    static ConfigurationManager& instance();

    // Méthodes pour définir les paramètres
    void setMusicEnabled(bool enabled);
    void setSoundLevel(int level);
    void setLanguage(const QString& language);

signals:
    void musicEnabledChanged(bool enabled);
    void soundLevelChanged(int level);
    void languageChanged(const QString& language);

private:
    ConfigurationManager() = default; // Constructeur privé
    Q_DISABLE_COPY(ConfigurationManager)
};

#endif // CONFIGURATIONMANAGER_H
