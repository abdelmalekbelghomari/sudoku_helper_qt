#ifndef FIGURESDISPLAYER_H
#define FIGURESDISPLAYER_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>

class MainWindow;
class SudokuDrawer;
class FiguresDisplayer : public QWidget {
    Q_OBJECT

public:
    explicit FiguresDisplayer(QWidget *parent = nullptr);
    void clearAll();
    // void setupInitialUI();
    // void clearLayout(QLayout* layout);
    // Adjust or add these functions based on your implementation needs
    void setNumbers(const QString& numbers);  // Adjusted to setNumber which is not previously declared
    // If you plan to have separate functionalities
    void setEditable(bool editable);  // Ensure this is declared if you use it
    void setFixedNumber(int number);  // Ensure this is declared if you use it
    // void updateChoices();
    void filterNumbers();
    void applyRestrictions(QComboBox* sender, const QString& value);
    void restoreValues();
    void restoreValuesForSelection(const QString& value);
    QWidget* widgetAt(int row, int col);
    void setSudokuDrawer(SudokuDrawer* drawer);
    QString buildGridRepresentation();
    void checkGameCompletion();
    void displayWinMessage();
    void displayWinMessageInNewWindow();
    void lockAllComboBoxes();
    void setSolution(const QString &solution);

public slots:
    void onComboBoxChanged(int index);
private:
    QLabel *numberLabel;
    QComboBox *numberComboBox;
    QGridLayout *layout;
    QMap<QComboBox*, QStringList> removedValuesFromCombos;
    QMap<QString, QList<QComboBox*>> sourceOfRemovedValues;
    SudokuDrawer* _drawer = nullptr;
    

    void createFixedNumber(int number, int position);  // Assuming this is correctly declared and implemented
    void createComboBox(int position);  // Assuming this is correctly declared and implemented

signals:
    void gameIsCompleted();
protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // FIGURESDISPLAYER_H
