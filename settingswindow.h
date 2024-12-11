#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QtWidgets/QDialog>
#include <string.h>
#include <QString>
#include <QDebug>

class MainWindow;

namespace Ui {
    class SettingsWindow;
}

// Settings Window class
class SettingsWindow : public QDialog {
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0, MainWindow *mainwindow=0);
    ~SettingsWindow();

    int getNumOfMines() {
        return numOfMines;
    }

    QString getBoardSize() {
        return boardSize;
    }

private:
    Ui::SettingsWindow *ui;
    int numOfMines;
    QString boardSize;
    MainWindow* mainWindow;

private slots:
    void on_pushButton_easy_clicked();
    void on_pushButton_medium_clicked();
    void on_pushButton_hard_clicked();
};

#endif // SETTINGSWINDOW_H
