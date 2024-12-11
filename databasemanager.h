#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "qsqltablemodel.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QDebug>

class DatabaseManager {
public:
    static DatabaseManager& instance() {
        static DatabaseManager instance;
        return instance;
    }

    bool openDatabase();
    void closeDatabase();
    QSqlQuery* createQuery();
    bool executeQuery(const QString& queryString);
    bool insertRecord(const QString& name, const QString& difficult, int time);
    QSqlTableModel* createTableModel();

private:
    DatabaseManager() {
        openDatabase();
    }
    ~DatabaseManager() {
        closeDatabase();
    }

    QSqlDatabase db;
    QString dbPath;
};

#endif // DATABASEMANAGER_H
