#include "databasemanager.h"

bool DatabaseManager::openDatabase() {
    QString userPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(userPath);
    if (!dir.exists()) {
        dir.mkpath(userPath);
    }
    dbPath = userPath + "/record.db";

    if (!QFile::exists(dbPath)) {
        if (!QFile::copy(":/db/record.db", dbPath)) {
            qDebug() << "Failed to copy database file";
            return false;
        }
    }

    QFile dbFile(dbPath);
    if (!dbFile.setPermissions(QFile::ReadOwner | QFile::WriteOwner | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOther | QFile::WriteOther)) {
        qDebug() << "Failed to set database file permissions";
        return false;
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return false;
    }

    QSqlQuery query(db);
    if (!query.exec("CREATE TABLE IF NOT EXISTS Records(name TEXT, difficult TEXT, time INTEGER);")) {
        qDebug() << "Table not created:" << query.lastError().text();
        return false;
    }

    return true;
}

void DatabaseManager::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

QSqlQuery* DatabaseManager::createQuery() {
    return new QSqlQuery(db);
}

bool DatabaseManager::executeQuery(const QString& queryString) {
    QSqlQuery query(db);
    return query.exec(queryString);
}

bool DatabaseManager::insertRecord(const QString& name, const QString& difficult, int time) {
    QSqlQuery query(db);

    // Проверяем, существует ли уже запись с таким именем и сложностью
    query.prepare("SELECT time FROM Records WHERE name = :name AND difficult = :difficult");
    query.bindValue(":name", name);
    query.bindValue(":difficult", difficult);
    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int existingTime = query.value(0).toInt();
        if (time < existingTime) {
            // Обновляем запись, если новое время меньше
            query.prepare("UPDATE Records SET time = :time WHERE name = :name AND difficult = :difficult");
            query.bindValue(":time", time);
            query.bindValue(":name", name);
            query.bindValue(":difficult", difficult);
            if (!query.exec()) {
                qDebug() << "Update failed:" << query.lastError().text();
                return false;
            }
        }
    } else {
        // Добавляем новую запись, если не существует
        query.prepare("INSERT INTO Records (name, difficult, time) VALUES (:name, :difficult, :time)");
        query.bindValue(":name", name);
        query.bindValue(":difficult", difficult);
        query.bindValue(":time", time);
        if (!query.exec()) {
            qDebug() << "Insert failed:" << query.lastError().text();
            return false;
        }
    }

    return true;
}

QSqlTableModel* DatabaseManager::createTableModel() {
    QSqlTableModel* model = new QSqlTableModel(nullptr, db);
    model->setTable("Records");
    return model;
}
