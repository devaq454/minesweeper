#include "results.h"
#include "ui_results.h"
#include "databasemanager.h"
#include "settingswindow.h"

// constructor
Results::Results(QWidget *parent, SettingsWindow *settingsWindow) :
    QDialog(parent),
    ui(new Ui::Results) {
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    // TODO
    QString currentDifficult;
    if (settingsWindow->getBoardSize() == "9x9")
        currentDifficult = "easy";
    else if (settingsWindow->getBoardSize() == "15x15")
        currentDifficult = "medium";
    else
        currentDifficult = "hard";

    model = DatabaseManager::instance().createTableModel();
    model->setFilter(QString("difficult = '%1'").arg(currentDifficult));
    model->setSort(model->fieldIndex("time"), Qt::AscendingOrder); // Сортировка по полю "time" в порядке возрастания
    model->select();

    ui->tableView->setModel(model);
}


// destructor
Results::~Results() {
    delete ui;
}
