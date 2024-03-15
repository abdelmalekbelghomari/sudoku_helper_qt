#ifndef FIGURESDISPLAYER_H
#define FIGURESDISPLAYER_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
class FiguresDisplayer : public QWidget {
    Q_OBJECT

public:
    explicit FiguresDisplayer(QWidget *parent = nullptr);
    void clear();
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

public slots:
    void onComboBoxChanged(int index);
private:
    QLabel *numberLabel;
    QComboBox *numberComboBox;
    QGridLayout *layout;
    QMap<QComboBox*, QStringList> removedValuesFromCombos;
    QMap<QString, QList<QComboBox*>> sourceOfRemovedValues;

    void createFixedNumber(int number, int position);  // Assuming this is correctly declared and implemented
    void createComboBox(int position);  // Assuming this is correctly declared and implemented
};

#endif // FIGURESDISPLAYER_H
