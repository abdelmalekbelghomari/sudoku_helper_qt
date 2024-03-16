#include "SudokuModel.h"

SudokuModel::SudokuModel(QObject *parent) : QObject(parent) {
}

QPoint SudokuModel::getWidgetPosition(int row, int col) {
    // Cette méthode pourrait retourner simplement la position
    // ou toute autre logique spécifique à votre modèle
    return QPoint(row, col);
}