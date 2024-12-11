#ifndef RESULTS_H
#define RESULTS_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTableWidget>
#include "QSqlTableModel"
#include <string.h>
#include <QDebug>
#include <QString>

namespace Ui {
    class Results;
}

class SettingsWindow;

// Results Window class
class Results : public QDialog {
    Q_OBJECT

public:
    explicit Results(QWidget *parent = 0, SettingsWindow *settingsWindow = 0);
    ~Results();
    QSqlTableModel *model;
    SettingsWindow *settingsWindow;

private:
    Ui::Results *ui;


};

#endif // RESULTS_H
