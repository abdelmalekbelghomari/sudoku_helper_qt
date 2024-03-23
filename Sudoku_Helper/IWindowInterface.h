#ifndef IWINDOWINTERFACE_H
#define IWINDOWINTERFACE_H

#include <QObject>
#include "ConfigurationManager.h"

class IWindowInterface : public QObject
{
    Q_OBJECT

public:
    explicit IWindowInterface(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~IWindowInterface() {}

    // Définissez ici les méthodes virtuelles pures que toutes vos fenêtres doivent implémenter
    virtual void setupUi() = 0; // Pour configurer l'interface utilisateur
    virtual void connectSignalsSlots() = 0; // Pour connecter tous les signaux et slots
    virtual void applySettings() = 0; // Pour appliquer les paramètres spécifiques à la fenêtre
private:
    ConfigurationManager & _configurationManager = ConfigurationManager::instance();

};

#endif // IWINDOWINTERFACE_H
