#include "IWindowInterface.h"

void hideAndDisplay(QMainWindow* screenToHide, QMainWindow* screenToDisplay) {
    if (screenToHide) {
        screenToHide->hide();
    }
    if (screenToDisplay) {
        screenToDisplay->show();
    }
}
