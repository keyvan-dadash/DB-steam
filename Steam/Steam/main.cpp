#include "mainpresenter.h"

#include <QApplication>

#include "database.h"
#include "UserQueryAbstract.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const char* driverName = "QPSQL";
    DataBase *database = new DataBase(driverName);
    UserQueryAbstract *userQ = database->getUserQuery();
    userQ->getUserGames("keyvan");
    MainPresenter w;
    w.show();
    return a.exec();
}
