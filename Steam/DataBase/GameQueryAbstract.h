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

    virtual QList<Game> getGamesOrderedByLikes() = 0;

    virtual QList<Game> getGamesOrderedByNumberOfPurchase() = 0;

    virtual QList<Game> getNewGames() = 0;

    virtual QList<Game> getFeaturedGames() = 0;

    virtual QList<Game> getGamesByGenres(QList<QString> genres) = 0;

};

#endif // GAMEQUERYABSTRACT_H
