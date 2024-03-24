#ifndef IWINDOWINTERFACE_H
#define IWINDOWINTERFACE_H

#include <QMainWindow>
#include "ConfigurationManager.h"

class IWindowInterface : public QMainWindow
{
    Q_OBJECT // Ajout du support Qt Meta-Object pour les signaux et slots

public:
    explicit IWindowInterface(QWidget *parent = nullptr) : QMainWindow(parent) {}
    virtual ~IWindowInterface() {}

    // Utilisation de pointeurs pour manipuler les fenêtres

private:
    ConfigurationManager & _configurationManager = ConfigurationManager::instance();
};

void hideAndDisplay(QMainWindow *screenToHide, QMainWindow *screenToDisplay);

#endif // IWINDOWINTERFACE_H
