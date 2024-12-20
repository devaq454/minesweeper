#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QDir>
#include <QQueue>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QInputDialog>
#include <QTimer>
#include "qrightclickbutton.h"

namespace Ui {
    class PlayWindow;
}

class SettingsWindow;

// Play Window class
class PlayWindow : public QDialog {
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = 0, int num = 5, QString size = "10x10",
                        SettingsWindow *settingsWindow = 0);
    ~PlayWindow();

private:
    Ui::PlayWindow *ui;         // pointer to ui component
    int numOfMines;             // number of mines
    int minesCounter;           // number of mines left
    int rows;                   // number of rows
    int cols;                   // number of columns
    int clickedButton;          // number of clicked button
    int secondsAfterStart;      // for time counter
    QString boardSize;          // number of rows and cols as QString
    QRightClickButton **butArr; // array with all buttons
    QTimer *timer;              // time counter

    int *mines_arr;             // array of mines
    int* visited_arr;           // array of marked cells

    SettingsWindow *settingsWindow;

private slots:
    void on_button_clicked();
    void on_right_clicked();
    bool checkIfMine(int);
    int* generateMines(int);
    int checkNeighbourCells(int);
    int checkNeighbourCell(int, int);
    void setIconToButton(QRightClickButton*, int);
    bool checkIfValidCoord(int, int);
    int checkForMinesCount(int, int);
    bool checkIfEnd();
    void timeCounterUpdate();
    void addResult(QString);
};

#endif // PLAYWINDOW_H
