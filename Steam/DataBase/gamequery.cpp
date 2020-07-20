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
    game.images = this->getGameFiles(game.title);
    return game;
}

Genre GameQuery::toGenre(QSqlQuery genreQ)
{
    QSqlQueryModel model;
    model.setQuery(genreQ);
    Genre genre;
    genre.id = model.record(0).value("id").toInt();
    genre.type = model.record(0).value("type").toString();
    return genre;
}

QList<Game> GameQuery::toGameList(QSqlQuery gameQ)
{
    QSqlQueryModel model;
    QList<Game> gameList;
    model.setQuery(gameQ);
    for(int i = 0; i < model.rowCount(); i++) {
        Game game;
        game.title = model.record(i).value("title").toString();
        game.date_of_publish = model.record(i).value("date_of_publish").toString();
        game.description = model.record(i).value("description").toString();
        game.likes = model.record(i).value("likes").toString();
        game.dislikes = model.record(i).value("dislikes").toString();
        game.attr = model.record(i).value("attr").toString();
        game.price = model.record(i).value("price").toString();
        game.update_id = model.record(i).value("update_id").toString();
        game.number_of_purchase = model.record(i).value("number_of_purchase").toString();
        game.companyName = model.record(i).value("name").toString();
        game.images = this->getGameFiles(game.title);
        gameList.push_back(game);
    }
    return gameList;
}

QList<Genre> GameQuery::toGenreList(QSqlQuery genreQ)
{
    QSqlQueryModel model;
    QList<Genre> genreList;
    model.setQuery(genreQ);
    for(int i = 0; i < model.rowCount(); i++) {
        Genre genre;
        genre.id = model.record(i).value("id").toInt();
        genre.type = model.record(i).value("type").toString();
        genreList.push_back(genre);
    }
    return genreList;
}

QList<File> GameQuery::getGameFiles(QString name)
{
    QList<File> gameImages;

    QSqlQuery gameImage;
    gameImage.prepare("select * from file where file.party_id = (select game.contents from game where game.title = :name);");
    gameImage.bindValue(":name", name);
    gameImage.exec();
    QSqlQueryModel model;
    model.setQuery(gameImage);
    qInfo() << gameImage.executedQuery();
    for (int i = 0; i < model.rowCount(); ++i) {
        File file;
        file.size = model.record(i).value("size").toString();
        file.type = model.record(i).value("type").toString();
        file.url = model.record(i).value("file_url").toString();
        gameImages.push_back(file);
    }
    return gameImages;
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
    gameQ.prepare("select * from game order by date_of_publish desc;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGameList(gameQ);
}

QList<Game> GameQuery::getFeaturedGames()
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from game where attr like '1%' order by date_of_publish desc;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGameList(gameQ);
}

QList<Game> GameQuery::getBestOfferGames()
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from game where attr like '_%1%_' order by date_of_publish desc;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGameList(gameQ);
}

QList<Game> GameQuery::getEarlyAccessGames()
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from game where attr like '%1' order by date_of_publish desc;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();

    return this->toGameList(gameQ);
}

QList<Game> GameQuery::getGamesByGenres(QList<QString> genres)
{
    QString genresStr = "";

    if (genres.size() == 1) {
        genresStr.append("'" + genres[0] + "'");
    }
    else {
        foreach(QString genre, genres) {
            genresStr.append("'" + genre + "'");
            if(genres.indexOf(genre) != genres.size() - 1)
                genresStr.append(", ");
        }
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

QList<Game> GameQuery::getLastUpdatedGames()
{
    QSqlQuery gameQ;
    gameQ.prepare("select distinct * from updatetable left join game on game.id = updatetable.game_id order by updatetable.update_date desc limit 10;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();
    return this->toGameList(gameQ);
}

QList<Game> GameQuery::getFreeGames()
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from game where price = 0 limit 100;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();
    return this->toGameList(gameQ);
}

QList<Game> GameQuery::mostPlayedGames()
{
    QSqlQuery gameQ;
    gameQ.prepare("select * from (select game_id, sum(total_gameplay) from game_purchase group by game_id) gpl"
                  " left join game on game.id = gpl.game_id order by sum desc limit 10;");
    gameQ.exec();
    qInfo() << gameQ.executedQuery();
    return this->toGameList(gameQ);
}

QList<Genre> GameQuery::getGenres()
{
    QSqlQuery genreQ;
    genreQ.prepare("select * from genre order by id");
    genreQ.exec();
    qInfo() << genreQ.executedQuery();
    return this->toGenreList(genreQ);
}
