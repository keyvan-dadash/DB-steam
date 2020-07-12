#include "store.h"
#include "ui_store.h"

Store::Store(QWidget *parent):
    QWidget(parent), ui(new Ui::Store)
{
    ui->setupUi(this);
    ui->quickCard->setSource(QUrl(QStringLiteral("qrc:/GameCard.qml")));

    obj = ui->quickCard->rootObject();

    Game game,game1;
    game.title = "A Plague Tale: Innocence";
    game.price = "$49.99";
    game.description = "About 2 sister and brother";
    game.images = QList<QString>{
            "file:///D:/fucking uni/DB/project/ex4.jpg",
            "file:///D:/fucking uni/DB/project/ex2.jpg",
            "file:///D:/fucking uni/DB/project/ex3.jpg",
            "file:///D:/fucking uni/DB/project/ex1.jpg"};

    game1.title = "Fallout 76";
    game1.price = "$59.99";
    game1.description = "Famouse Fallout Series";
    game1.images = QList<QString>{
            "file:///D:/fucking uni/DB/project/exxx4.jpg",
            "file:///D:/fucking uni/DB/project/exxx2.jpg",
            "file:///D:/fucking uni/DB/project/exxx3.jpg",
            "file:///D:/fucking uni/DB/project/exxx1.jpg"};

    QList<Game> gg{game, game1};
    this->setUpTop100GamesView(gg);
}

Store::~Store()
{
    delete ui;
}

QVariantMap Store::gameToVariantMap(Game game)
{
    QVariantMap map;
    map.insert("title", game.title);
    //map.insert("date_of_publish", game.date_of_publish);
    map.insert("description", game.description);
    //map.insert("likes", game.likes);
    //map.insert("dislikes", game.dislikes);
    //map.insert("attr", game.attr);
    map.insert("price", game.price);
    //map.insert("update_id", game.update_id);
    //map.insert("number_of_purchase", game.number_of_purchase);
    map.insert("images", this->toVariantList(game.images));

    return map;
}

void Store::setGames(QList<Game> &games)
{
    QVariantList gameList;
    foreach(Game game, games) {
        gameList.push_back(this->gameToVariantMap(game));
    }

    QMetaObject::invokeMethod(obj, "setObjectsArray",
                              Q_ARG(QVariant, QVariant::fromValue(gameList)));
}

void Store::setUpFeatureGamesView(QList<Game> games)
{
    this->setGames(games);
    QMetaObject::invokeMethod(obj, "createFeatureGamesView");
}

void Store::setUpTop100GamesView(QList<Game> games)
{
    this->setGames(games);
    QMetaObject::invokeMethod(obj, "createTop100GamesView");
}

template<typename T>
QVariantList Store::toVariantList(const QList<T> &list)
{
    QVariantList newList;
    foreach( const T &item, list )
        newList << item;

    return newList;
}
