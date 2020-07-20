#include "store.h"
#include "ui_store.h"

Store::Store(DataBase *database, int view, QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Store), database(database), view(view)
{
    ui->setupUi(this);
    ui->quickCard->setSource(QUrl(QStringLiteral("qrc:/GameCard.qml")));

    obj = ui->quickCard->rootObject();
    this->makeConnection();

    MainView mv = MainView(view);

    switch (mv) {
    case featuredGames:
        this->setUpFeatureGamesView(this->database->getGameQuery()->getFeaturedGames().mid(0, 5));
        break;
    case newGames:
        this->setUpNewGamesView(this->database->getGameQuery()->getNewGames().mid(0, 15));
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

CopyableWidget *Store::copy()
{
    return new Store(database, view);
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

void Store::setUpNewGamesView(QList<Game> games)
{
    this->setGames(games);
    QMetaObject::invokeMethod(obj, "createNewGamesView");
}

void Store::openGamePage(QString gameName)
{
    GamePage *gamepage = new GamePage(database, qobject_cast<QWidget*>(this->parent()));
    gamepage->setGame(gameName);
    gamepage->show();
    this->deleteLater();
}

void Store::storeChangeItem(int item)
{
    ui->comboBoxStore->setCurrentIndex(0);
    switch (item) {
    case 1:
        this->setUpTop100GamesView(this->database->getGameQuery()->getBestOfferGames().mid(0,100));
        break;
    case 2:
        this->setUpTop100GamesView(this->database->getGameQuery()->getFreeGames().mid(0,100));
        break;
    }
}

void Store::gameChangeItem(int item)
{
    ui->comboBoxGames->setCurrentIndex(0);
    switch (item) {
    case 1:
        this->setUpFeatureGamesView(this->database->getGameQuery()->getGamesOrderedByLikes().mid(0,10));
        break;
    case 2:
        this->setUpFeatureGamesView(this->database->getGameQuery()->getLastUpdatedGames().mid(0,10));
        break;
    case 3:
        this->setUpTop100GamesView(this->database->getGameQuery()->getEarlyAccessGames().mid(0,100));
        break;
    case 4:
        this->setUpFeatureGamesView(this->database->getGameQuery()->mostPlayedGames().mid(0,10));
        break;
    }
}

void Store::makeConnection()
{
    QObject::connect(obj, SIGNAL(loadGamePage(QString)), this, SLOT(openGamePage(QString)));
    QObject::connect(ui->comboBoxStore, SIGNAL(currentIndexChanged(int)), this, SLOT(storeChangeItem(int)));
    QObject::connect(ui->comboBoxGames, SIGNAL(currentIndexChanged(int)), this, SLOT(gameChangeItem(int)));
}

template<typename T>
QVariantList Store::toVariantList(const QList<T> &list)
{
    QVariantList newList;
    foreach( const T &item, list )
        newList << item;

    return newList;
}
