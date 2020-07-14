#include "database.h"

DataBase::DataBase(const char *driver, QObject *parent) : QObject(parent)
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase(driver));

    this->connect("localhost", "postgres", "postgres", "postgres", 5433);
}

DataBase::~DataBase()
{
    this->disConnect();
    delete db;
}

QSqlDatabase *DataBase::connect(const QString &server, const QString &databaseName, const QString &userName, const QString &password, int port)
{
    db->setConnectOptions();
    db->setHostName(server);
    db->setDatabaseName(databaseName);
    db->setUserName(userName);
    db->setPassword(password);
    db->setPort(port);

    if(db->open()) {
        return db;
    }
    else {
        qInfo() << db->lastError();
        return NULL;
    }
}

bool DataBase::executeQuery(QSqlQuery *query)
{
    db->transaction();
    bool queryRes = query->exec();
    if (query->lastError().type() != QSqlError::NoError || !queryRes)
    {
        qDebug() << query->lastError().text();
        db->rollback();
        return false;
    }
    db->commit();
    return true;
}

void DataBase::disConnect()
{
    db->close();
}

UserQueryAbstract *DataBase::getUserQuery()
{
    return new UserQuery();
}
