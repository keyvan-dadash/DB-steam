#include "gamequery.h"

GameQuery::GameQuery() : GameQueryAbstract()
{

}

Game GameQuery::toGame(QSqlQuery gameQ)
{
    QSqlQueryModel model;
    model.setQuery(gameQ);
    Game game;
    game.title = model.record(0).value("title").toString();
    game.date_of_publish = model.record(0).value("date_of_publish").toString();
    game.description = model.record(0).value("description").toString();
    game.likes = model.record(0).value("likes").toString();
    game.dislikes = model.record(0).value("dislikes").toString();
    game.attr = model.record(0).value("attr").toString();
    game.price = model.record(0).value("price").toString();
    game.update_id = model.record(0).value("update_id").toString();
    game.number_of_purchase = model.record(0).value("number_of_purchase").toString();
    game.companyName = model.record(0).value("name").toString();
    return game;
}

QList<Game> GameQuery::toGameList(QSqlQuery gameQ)
{
    QSqlQueryModel model;
    QList<Game> gameList;
    model.setQuery(gameQ);
    for(int i = 0; i < model.rowCount(); i++) {
        Game game;
        game.title = model.record(0).value("title").toString();
        game.date_of_publish = model.record(0).value("date_of_publish").toString();
        game.description = model.record(0).value("description").toString();
        game.likes = model.record(0).value("likes").toString();
        game.dislikes = model.record(0).value("dislikes").toString();
        game.attr = model.record(0).value("attr").toString();
        game.price = model.record(0).value("price").toString();
        game.update_id = model.record(0).value("update_id").toString();
        game.number_of_purchase = model.record(0).value("number_of_purchase").toString();
        game.companyName = model.record(0).value("name").toString();
        gameList.push_back(game);
    }
    return gameList;
}

Game GameQuery::getGameByName(QString name)
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from game left join company on company.id = game.publisher where game.title = :name;");
    gameQ.bindValue(":name", name);
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGame(gameQ);

}

QList<Game> GameQuery::getGamesOrderedByLikes()
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from game order by likes desc;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGameList(gameQ);
}

QList<Game> GameQuery::getGamesOrderedByNumberOfPurchase()
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from game order by number_of_purchase desc;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGameList(gameQ);
}

QList<Game> GameQuery::getNewGames()
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from game order by number_of_purchase desc;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGameList(gameQ);
}

QList<Game> GameQuery::getFeaturedGames()
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from game order by number_of_purchase desc;"); //we must decied about attr in game model
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGameList(gameQ);
}

QList<Game> GameQuery::getGamesByGenres(QList<QString> genres)
{
    QString genresStr = "";

    foreach(QString genre, genres) {
        genresStr.append("'" + genre + "'");
        if(genres.indexOf(genre) != genres.size() - 1)
            genresStr.append(", ");
    }
    qInfo() << genresStr;
    QSqlQuery gameQ;
    gameQ.prepare("with filterGame as ("
                  " select game.id as res_game_id from game left join game_genre on game.id = game_genre.game_id left join genre on"
                  " game_genre.genre_id = genre.id where genre.type in "
                  " (" + genresStr + ") group by game.id having count(genre.type) = :number"
                  " )"
                  " select game.* from game right join filterGame on filterGame.res_game_id = game.id;");
    gameQ.bindValue(":number", genres.size());
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGameList(gameQ);
}
