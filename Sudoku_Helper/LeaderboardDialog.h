#ifndef LEADERBOARDDIALOG_H
#define LEADERBOARDDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

class LeaderboardDialog : public QDialog {
    Q_OBJECT

public:
    explicit LeaderboardDialog(QWidget *parent = nullptr);

private:
    void loadAndDisplayData();
};

#endif // LEADERBOARDDIALOG_H
