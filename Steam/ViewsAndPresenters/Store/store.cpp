#include "store.h"
#include "ui_store.h"

Store::Store(DataBase *database, int view, QWidget *parent):
    QWidget(parent), ui(new Ui::Store), database(database)
{
    ui->setupUi(this);
    ui->quickCard->setSource(QUrl(QStringLiteral("qrc:/GameCard.qml")));

    obj = ui->quickCard->rootObject();

    MainView mv = MainView(view);

    switch (mv) {
    case featuredGames:
        this->setUpFeatureGamesView(this->database->getGameQuery()->getFeaturedGames().mid(0, 5));
        break;
    case newGames:
        this->setUpTop100GamesView(this->database->getGameQuery()->getNewGames());
        break;
    case topGames:
        this->setUpTop100GamesView(this->database->getGameQuery()->getGamesOrderedByLikes());
        break;
    case topSales:
        this->setUpTop100GamesView(this->database->getGameQuery()->getGamesOrderedByNumberOfPurchase());
        break;
    default:
        this->setUpFeatureGamesView(this->database->getGameQuery()->getFeaturedGames().mid(0, 5));
        break;
    }
}

Store::~Store()
{
    delete ui;
}

void Store::setGames(QList<Game> &games)
{
    QVariantList gameList;
    foreach(Game game, games) {
        gameList.push_back(game.toVariantMap());
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
