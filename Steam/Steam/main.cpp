#include "mainpresenter.h"

#include <QApplication>
#include <QList>

#include "database.h"
#include "UserQueryAbstract.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const char* driverName = "QPSQL";
    DataBase *database = new DataBase(driverName);
    qInfo() << database->getGameQuery()->getGamesByGenres(QList<QString>{"Adventure", "Simulation"})[0].description;
    MainPresenter w;
    w.show();
    return a.exec();
}
