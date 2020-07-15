#ifndef GAMEQUERY_H
#define GAMEQUERY_H


#include <QtSql>
#include <QList>
#include <QString>
#include <QDebug>


#include "models.h"
#include "GameQueryAbstract.h"

class GameQuery : public GameQueryAbstract
{

public:
    GameQuery();

    Game toGame(QSqlQuery gameQ);

    QList<Game> toGameList(QSqlQuery gameQ);

    Game getGameByName(QString name) override;

    QList<Game> getGamesOrderedByLikes() override;

    QList<Game> getGamesOrderedByNumberOfPurchase() override;

    QList<Game> getNewGames() override;

    QList<Game> getFeaturedGames() override;

    QList<Game> getGamesByGenres(QList<QString> genres) override;
};

#endif // GAMEQUERY_H
