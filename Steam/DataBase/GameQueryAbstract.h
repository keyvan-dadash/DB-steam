#ifndef GAMEQUERYABSTRACT_H
#define GAMEQUERYABSTRACT_H

#include <QtSql>
#include <QString>
#include <QList>

#include "models.h"


class GameQueryAbstract
{
public:

    virtual Game getGameByName(QString name) = 0;

    virtual QList<File> getGameFiles(QString name) = 0;

    virtual QList<Game> getGamesOrderedByLikes() = 0;

    virtual QList<Game> getGamesOrderedByNumberOfPurchase() = 0;

    virtual QList<Game> getNewGames() = 0;

    virtual QList<Game> getFeaturedGames() = 0;

    virtual QList<Game> getBestOfferGames() = 0;

    virtual QList<Game> getEarlyAccessGames() = 0;

    virtual QList<Game> getGamesByGenres(QList<QString> genres) = 0;

    virtual QList<Game> getLastUpdatedGames() = 0;

    virtual QList<Game> getFreeGames() = 0;

    virtual QList<Game> mostPlayedGames() = 0;

    virtual QList<Genre> getGenres() = 0;

};

#endif // GAMEQUERYABSTRACT_H
