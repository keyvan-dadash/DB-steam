#include "store.h"
#include "ui_store.h"

Store::Store(QWidget *parent):
    QWidget(parent), ui(new Ui::Store)
{
    ui->setupUi(this);
    ui->quickCard->setSource(QUrl(QStringLiteral("qrc:/GameCard.qml")));

    obj = ui->quickCard->rootObject();

    Game game,game1;

    File file1,file2;
    file1.url = "file:///D:/fucking uni/DB/project/ex4.jpg";
    file2.url = "file:///D:/fucking uni/DB/project/exxx4.jpg";

    game.title = "A Plague Tale: Innocence";
    game.price = "$49.99";
    game.description = "About 2 sister and brother";
    game.images = QList<File>{file1};

    game1.title = "Fallout 76";
    game1.price = "$59.99";
    game1.description = "Famouse Fallout Series";
    game1.images = QList<File>{file2};

    QList<Game> gg{game, game1};
    this->setUpTop100GamesView(gg);
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
