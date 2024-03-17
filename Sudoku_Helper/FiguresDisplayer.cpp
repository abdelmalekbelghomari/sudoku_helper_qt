#include "FiguresDisplayer.h"
#include <QLabel>
#include <QComboBox>
#include <QSet>
#include "SudokuDrawer.h"
#include <QMessageBox>

FiguresDisplayer::FiguresDisplayer(QWidget *parent) : QWidget(parent), layout(new QGridLayout(this)) {
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

void FiguresDisplayer::clearAll() {  
    // Supprimer tous les widgets du layout
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget(); // Supprime le widget
        delete item; // Supprime l'élément de layout
    }
}

void FiguresDisplayer::setSudokuDrawer(SudokuDrawer* drawer) {
    _drawer = drawer;
}

void FiguresDisplayer::setNumbers(const QString& numbers) {
    // Vérification préalable
    if (numbers.length() != 81) return; // Assurez-vous qu'il y a exactement 9 chiffres
    if (_drawer) {
        _drawer->drawGrid(numbers); // Dessinez la grille actuelle
    }
    for (int i = 0; i < numbers.length(); ++i) {
        int number = numbers.at(i).digitValue();

        if (number == 0) {
            createComboBox(i);
        } else {
            createFixedNumber(number, i);
        }
    }
}

void FiguresDisplayer::createFixedNumber(int number, int position) {
    QLabel *label = new QLabel(QString::number(number), this);
    label->setAlignment(Qt::AlignCenter);
    int row = position / 9;
    int col = position % 9;
    layout->addWidget(label, row, col);
}

void FiguresDisplayer::createComboBox(int position) {
    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItem(""); // Item vide pour la sélection 'effacer'
    for (int i = 1; i <= 9; ++i) {
        comboBox->addItem(QString::number(i));
    }
    int row = position / 9;
    int col = position % 9;
    layout->addWidget(comboBox, row, col);
    comboBox->setProperty("previousValue", "");
    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));
}

QWidget* FiguresDisplayer::widgetAt(int row, int col) {
    // QGridLayout::itemAtPosition retourne un QLayoutItem à la position donnée
    QLayoutItem* item = layout->itemAtPosition(row, col);
    if (item) {
        return item->widget(); // Retourne le widget associé à cet item, si disponible
    }
    return nullptr; // Si aucun item n'est trouvé à cette position, retourne nullptr
}

void FiguresDisplayer::onComboBoxChanged(int index) {
    QComboBox* senderComboBox = qobject_cast<QComboBox*>(sender());
    if (!senderComboBox) return;

    QString previousValue = senderComboBox->property("previousValue").toString();
    QString currentValue = index > 0 ? senderComboBox->itemText(index) : "";

    senderComboBox->setProperty("previousValue", currentValue);

    // Restaurez les valeurs retirées à cause de l'ancienne sélection, si elle existe
    if (!previousValue.isEmpty()) {
        restoreValuesForSelection(previousValue);
    }

    // Efface toutes les restrictions si l'index est 0 (sélection effacée)
    if (!currentValue.isEmpty()) {
        // Appliquez de nouvelles restrictions basées sur la nouvelle sélection
        applyRestrictions(senderComboBox, currentValue);
    }
    QString gridData = buildGridRepresentation();

    // Mettez à jour et redessinez la grille dans SudokuDrawer
    if (_drawer) {
        _drawer->drawGrid(gridData);
    }
    checkGameCompletion();
}

QString FiguresDisplayer::buildGridRepresentation() {
    QString gridData;
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            QWidget* widget = widgetAt(row, col);
            QComboBox* comboBox = qobject_cast<QComboBox*>(widget);
            QLabel* label = qobject_cast<QLabel*>(widget);
            if (comboBox && comboBox->currentIndex() != -1) {
                gridData += comboBox->currentText();
            } else if (label) {
                gridData += label->text();
            } else {
                gridData += "0"; // Supposons que "0" représente une cellule vide
            }
        }
    }
    return gridData;
}

void FiguresDisplayer::applyRestrictions(QComboBox* sender, const QString& value) {
    int senderIndex = layout->indexOf(sender);
    int senderRow = senderIndex / 9;
    int senderCol = senderIndex % 9;

    for (int i = 0; i < layout->count(); ++i) {
        QLayoutItem* item = layout->itemAt(i);
        QComboBox* comboBox = qobject_cast<QComboBox*>(item->widget());
        if (!comboBox || comboBox == sender) continue;

        int row = i / 9;
        int col = i % 9;
        int boxRow = row / 3, boxCol = col / 3;
        int senderBoxRow = senderRow / 3, senderBoxCol = senderCol / 3;

        if (row == senderRow || col == senderCol || (boxRow == senderBoxRow && boxCol == senderBoxCol)) {
            int findIndex = comboBox->findText(value);
            if (findIndex != -1) {
                comboBox->removeItem(findIndex);
                removedValuesFromCombos[comboBox].append(value); // Ajouter à la liste des valeurs retirées
                sourceOfRemovedValues[value].append(comboBox); // Enregistrer la source de la valeur retirée
            }
        }
    }
}


void FiguresDisplayer::filterNumbers() {
    // Parcourt tous les éléments du layout pour trouver les QComboBox
    for (int i = 0; i < layout->count(); ++i) {
        QLayoutItem* item = layout->itemAt(i);
        if (!item->widget()) continue; // Ignore les éléments sans widget

        // Calcule la position de l'élément dans la grille
        int row = i / 9;
        int col = i % 9;
        
        QComboBox* comboBox = qobject_cast<QComboBox*>(item->widget());
        // Continue uniquement si l'élément est un QComboBox
        if (!comboBox) continue;

        // Bloque les signaux temporairement pour éviter des appels récursifs
        bool signalsBlocked = comboBox->blockSignals(true);

        // Construit une liste de chiffres à retirer
        QSet<QString> numbersToRemove;
        for (int j = 0; j < layout->count(); ++j) {
            QLayoutItem* checkItem = layout->itemAt(j);
            if (!checkItem->widget()) continue;

            int checkRow = j / 9;
            int checkCol = j % 9;
            int boxStartRow = row / 3 * 3;
            int boxStartCol = col / 3 * 3;
            
            // Vérifie si l'élément est dans la même ligne, colonne ou carré 3x3
            if (checkRow == row || checkCol == col || (checkRow >= boxStartRow && checkRow < boxStartRow + 3 && checkCol >= boxStartCol && checkCol < boxStartCol + 3)) {
                QLabel* label = qobject_cast<QLabel*>(checkItem->widget());
                if (label && !label->text().isEmpty()) {
                    numbersToRemove.insert(label->text());
                }
            }
        }

        // Retire les chiffres trouvés des options du QComboBox
        for (const QString& number : qAsConst(numbersToRemove)) {
            int indexToRemove = comboBox->findText(number);
            if (indexToRemove != -1) {
                comboBox->removeItem(indexToRemove);
            }
        }

        // Restaure l'état précédent des signaux
        comboBox->blockSignals(signalsBlocked);
    }
}

void FiguresDisplayer::restoreValuesForSelection(const QString& value) {
    auto combos = sourceOfRemovedValues[value];
    for (QComboBox* combo : combos) {
        if (combo->findText(value) == -1) {
            combo->addItem(value);
        }
    }
    // Assurez-vous de nettoyer après la restauration
    sourceOfRemovedValues[value].clear();
}

void FiguresDisplayer::checkGameCompletion() {
    bool gameCompleted = true;
    for (int i = 0; i < layout->count(); ++i) {
        QLayoutItem* item = layout->itemAt(i);
        if (QComboBox* comboBox = qobject_cast<QComboBox*>(item->widget())) {
            if (comboBox->currentIndex() == 0) { // Si un comboBox est sur l'item vide
                gameCompleted = false;
                break;
            }
        }
    }

    if (gameCompleted) {
        lockAllComboBoxes();
        displayWinMessageInNewWindow();
        emit gameIsCompleted();
    }
}

void FiguresDisplayer::lockAllComboBoxes() {
    for (int i = 0; i < layout->count(); ++i) {
        QLayoutItem* item = layout->itemAt(i);
        if (QComboBox* comboBox = qobject_cast<QComboBox*>(item->widget())) {
            comboBox->setEnabled(false); // Désactiver le comboBox pour empêcher toute modification
        }
    }
}

void FiguresDisplayer::displayWinMessageInNewWindow() {
    QMessageBox::information(this, "Game Completed", "MONSTREE!");
}

void FiguresDisplayer::paintEvent(QPaintEvent *event) {
    
}

void FiguresDisplayer::setSolution(const QString &solution) {
    // Assurez-vous que la solution a exactement 81 caractères (9x9 Sudoku)
    if (solution.length() != 81) return;

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            // Calculer l'index linéaire basé sur la position de la grille
            int index = row * 9 + col;
            // Obtenir la valeur de la solution pour la cellule actuelle
            int value = solution.at(index).digitValue();

            // Trouver le widget dans la grille à la position actuelle
            QWidget* widget = widgetAt(row, col);
            QComboBox* comboBox = qobject_cast<QComboBox*>(widget);
            if (comboBox) {
                // Si la cellule est un QComboBox, mettez à jour sa valeur
                // Notez que les indices des QComboBox commencent par 0 pour l'item vide, donc +1 pour la valeur réelle
                comboBox->setCurrentIndex(value); // value est déjà dans la plage 1-9, conforme aux indices de QComboBox
            }
        }
    }
}