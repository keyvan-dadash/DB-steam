#include "library.h"
#include "ui_library.h"

Library::Library(DataBase *database, QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Library), database(database)
{
    ui->setupUi(this);
    ui->quickWidgetLibrary->setSource(QUrl(QStringLiteral("qrc:/libraryMain.qml")));
    this->obj = ui->quickWidgetLibrary->rootObject();

    this->setUpLibrary(database->getUserQuery()->getUserGames(this->database->username));
}

Library::~Library()
{
    delete ui;
}

CopyableWidget *Library::copy()
{
    return new Library(database);
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
