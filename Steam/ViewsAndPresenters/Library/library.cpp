#include "library.h"
#include "ui_library.h"

Library::Library(QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Library)
{
    ui->setupUi(this);
    ui->quickWidgetLibrary->setSource(QUrl(QStringLiteral("qrc:/libraryMain.qml")));
    this->obj = ui->quickWidgetLibrary->rootObject();

    const char* driverName = "QPSQL";
    DataBase *database = new DataBase(driverName);
    this->setUpLibrary(database->getUserQuery()->getUserGames("keyvan"));
}

Library::~Library()
{
    delete ui;
}

CopyableWidget *Library::copy()
{
    return new Library();
}

void Library::setUpLibrary(QList<Game> games)
{
    QVariantList gameList;
    foreach(Game game, games) {
        gameList.push_back(game.toVariantMap());
    }

    QMetaObject::invokeMethod(obj, "setObjectsArray",
                              Q_ARG(QVariant, QVariant::fromValue(gameList)));
}

template<typename T>
QVariantList Library::toVariantList( const QList<T> &list )
{
    QVariantList newList;
    foreach( const T &item, list )
        newList << item;

    return newList;
}
