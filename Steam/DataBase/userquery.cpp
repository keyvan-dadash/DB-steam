#include "userquery.h"

UserQuery::UserQuery() : UserQueryAbstract()
{

}

QList<Game> UserQuery::getUserGames(QString username)
{
    QSqlQuery userGames;
    userGames.prepare("select game.*, game_purchase.total_gameplay from users left join game_purchase on users.id = game_purchase.users_id left join game on"
                      " game_purchase.game_id = game.id where users.username = :username;");
    userGames.bindValue(":username", username);
    userGames.exec();
    QList<Game> userGameList;
    QSqlQueryModel model;
    model.setQuery(userGames);
    qInfo() << userGames.executedQuery();
    for (int i = 0; i < model.rowCount(); ++i) {
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
        userGameList.push_back(game);
    }
    return userGameList;
}

int UserQuery::getUserId(QString username)
{
    QSqlQuery userId;
    userId.prepare("select users.id from users where users.username = :username");
    userId.bindValue(":username", username);
    userId.exec();
    qInfo() << userId.executedQuery();
    QSqlQueryModel model;
    model.setQuery(userId);
    return model.record(0).value("id").toInt();
}

User UserQuery::getUser(QString username)
{
    QSqlQuery userQ;
    userQ.prepare("select * from users where id = :id;");
    userQ.bindValue(":id", this->getUserId(username));
    userQ.exec();

    QList<UserFriends> userFriendList;
    QSqlQueryModel model;
    model.setQuery(userQ);
    qInfo() << userQ.executedQuery();
    User user;
    user.username = model.record(0).value("username").toString();
    user.email = model.record(0).value("email").toString();
    user.bio = model.record(0).value("bio").toString();
    user.wallet = model.record(0).value("wallet").toString();
    user.level = model.record(0).value("level").toString();
    user.last_time_online = model.record(0).value("last_time_online").toString();
    user.nickname = model.record(0).value("nickname").toString();
    user.birth = model.record(0).value("birth").toString();
    return user;
}

QList<UserFriends> UserQuery::getUserFriends(QString username)
{
    QSqlQuery userFriends;
    userFriends.prepare("With friends as ("
                            "select friend_1_id as users_id from friend where friend_2_id = :id"
                            " union"
                            " select friend_2_id as users_id from friend where friend_1_id = :id"
                            ")"
                            " select users.* from friends left join users on users_id = users.id;");
    userFriends.bindValue(":id", this->getUserId(username));
    userFriends.exec();

    QList<UserFriends> userFriendList;
    QSqlQueryModel model;
    model.setQuery(userFriends);
    qInfo() << userFriends.executedQuery();
    for (int i = 0; i < model.rowCount(); ++i) {
        UserFriends friends;
        friends.username = model.record(i).value("username").toString();
        friends.email = model.record(i).value("email").toString();
        friends.last_time_online = model.record(i).value("last_time_online").toString();
        friends.bio = model.record(i).value("bio").toString();
        friends.level = model.record(i).value("level").toString();
        friends.nickname = model.record(i).value("nickname").toString();
        friends.birth = model.record(i).value("birth").toString();
        userFriendList.push_back(friends);
    }
    return userFriendList;
}

QList<UserBlocked> UserQuery::getUserBlocked(QString username)
{
    QSqlQuery userBlocked;
    userBlocked.prepare("select users.* from block left join users on blocked_id = users.id where blocker_id = :id;");
    userBlocked.bindValue(":id", this->getUserId(username));
    userBlocked.exec();

    QList<UserBlocked> userBlockedList;
    QSqlQueryModel model;
    model.setQuery(userBlocked);
    qInfo() << userBlocked.executedQuery();
    for (int i = 0; i < model.rowCount(); ++i) {
        UserBlocked blocked;
        blocked.username = model.record(i).value("username").toString();
        blocked.nickname = model.record(i).value("nickname").toString();
        blocked.last_time_online = model.record(i).value("last_time_online").toString();
        blocked.since = model.record(i).value("since").toString();
        userBlockedList.push_back(blocked);
    }
    return userBlockedList;
}

QList<UserInvites> UserQuery::getUserPending(QString username)
{
    QSqlQuery userPending;
    userPending.prepare("select * from invite left join users on users.id = invite.reciver_id where invite.sender_id = :id;");
    userPending.bindValue(":id", this->getUserId(username));
    userPending.exec();

    QList<UserInvites> userPendingList;
    QSqlQueryModel model;
    model.setQuery(userPending);
    qInfo() << userPending.executedQuery();
    for (int i = 0; i < model.rowCount(); ++i) {
        UserInvites userInvite;
        userInvite.username = model.record(i).value("username").toString();
        userInvite.nickname = model.record(i).value("nickname").toString();
        userInvite.receiver_nickname = model.record(i).value("nickname").toString();
        userInvite.last_time_online = model.record(i).value("last_time_online").toString();
        userInvite.status = model.record(i).value("status").toString();
        userInvite.invite_date = model.record(i).value("invite_date").toString();
        userPendingList.push_back(userInvite);
    }
    return userPendingList;
}

QList<UserInvites> UserQuery::getUserReceive(QString username)
{
    QSqlQuery userReceive;
    userReceive.prepare("select * from invite left join users on users.id = invite.sender_id where invite.reciver_id = :id;");
    userReceive.bindValue(":id", this->getUserId(username));
    userReceive.exec();

    QList<UserInvites> userReceiveList;
    QSqlQueryModel model;
    model.setQuery(userReceive);
    qInfo() << userReceive.executedQuery();
    for (int i = 0; i < model.rowCount(); ++i) {
        UserInvites userInvite;
        userInvite.username = model.record(i).value("username").toString();
        userInvite.nickname = model.record(i).value("nickname").toString();
        userInvite.receiver_nickname = model.record(i).value("nickname").toString();
        userInvite.last_time_online = model.record(i).value("last_time_online").toString();
        userInvite.status = model.record(i).value("status").toString();
        userInvite.invite_date = model.record(i).value("invite_date").toString();
        userReceiveList.push_back(userInvite);
    }
    return userReceiveList;
}
