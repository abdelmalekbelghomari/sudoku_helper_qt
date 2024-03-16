#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class HomeWindow : public QWidget {
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = nullptr);

signals:
    void startNewGame();

private slots:
    void onNewGameClicked();

private:
    QPushButton *newGameButton;
};

#endif // HOMEWINDOW_H
