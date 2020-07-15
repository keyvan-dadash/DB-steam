#ifndef USERQUERY_H
#define USERQUERY_H

#include <QList>
#include <QString>
#include <QtSql>

#include "UserQueryAbstract.h"
#include "models.h"

class UserQuery : public UserQueryAbstract
{
public:
    UserQuery();

    QList<Game> getUserGames(QString username) override;

    int getUserId(QString username) override;

    QList<File> getGameImages(QString name) override;

    User getUser(QString username) override;

    QList<UserFriends> getUserFriends(QString username) override;

    QList<UserBlocked> getUserBlocked(QString username) override;

    QList<UserInvites> getUserPending(QString username) override;

    QList<UserInvites> getUserReceive(QString username) override;
};

#endif // USERQUERY_H
