#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QIcon>
#include <QtWidgets/QPushButton>
#include <QDebug>
#include <QString>
#include <time.h>
#include <stdlib.h>
#include <settingswindow.h>
#include <playwindow.h>
#include <results.h>


namespace Ui {
    class MainWindow;
}

// Main Window class
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateLabelDifficulty(const QString &text);

private:
    Ui::MainWindow *ui;
    PlayWindow *plWindow;
    SettingsWindow *setWindow;
    Results *resWindow;

private slots:
    void on_pushResultsButton_clicked();
    void on_pushSettingsButton_clicked();
    void on_pushPlayButton_clicked();

};

#endif // MAINWINDOW_H
