#include "settingswindow.h"
#include "mainwindow.h"
#include "ui_settingswindow.h"



// constructor
SettingsWindow::SettingsWindow(QWidget *parent, MainWindow *mainWindow) :
        QDialog(parent),
        ui(new Ui::SettingsWindow),
        mainWindow(mainWindow)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    this->numOfMines = 10;
    this->boardSize = "9x9";
    mainWindow->updateLabelDifficulty("Сложность: easy");
}

// destructor
SettingsWindow::~SettingsWindow() {
    delete ui;
}



void SettingsWindow::on_pushButton_easy_clicked()
{
    // 9x9 10 mines
    this->numOfMines = 10;
    this->boardSize = "9x9";
    mainWindow->updateLabelDifficulty("Сложность: easy");
    this->hide();
}


void SettingsWindow::on_pushButton_medium_clicked()
{
    // 15x15 20 mines
    this->numOfMines = 20;
    this->boardSize = "15x15";
    mainWindow->updateLabelDifficulty("Сложность: medium");
    this->hide();
}


void SettingsWindow::on_pushButton_hard_clicked()
{
    // 20x20 30 mines
    this->numOfMines = 30;
    this->boardSize = "20x20";
    mainWindow->updateLabelDifficulty("Сложность: hard");
    this->hide();
}

