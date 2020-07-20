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

    Genre toGenre(QSqlQuery genreQ);

    QList<Game> toGameList(QSqlQuery gameQ);

    QList<Genre> toGenreList(QSqlQuery genreQ);

    QList<File> getGameFiles(QString name) override;

    Game getGameByName(QString name) override;

    QList<Game> getGamesOrderedByLikes() override;

    QList<Game> getGamesOrderedByNumberOfPurchase() override;

    QList<Game> getNewGames() override;

    QList<Game> getFeaturedGames() override;

    QList<Game> getBestOfferGames() override;

    QList<Game> getEarlyAccessGames() override;

    QList<Game> getGamesByGenres(QList<QString> genres) override;

    QList<Game> getLastUpdatedGames() override;

    QList<Game> getFreeGames() override;

    QList<Game> mostPlayedGames() override;

    QList<Genre> getGenres() override;

};

#endif // GAMEQUERY_H
