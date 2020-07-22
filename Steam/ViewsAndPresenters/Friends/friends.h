#ifndef FRIENDS_H
#define FRIENDS_H

#include "Friends_global.h"
#include <QWidget>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include <QList>

#include "../../Steam/copyablewidget.h"
#include "../../DataBase/models.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Friends; }
QT_END_NAMESPACE

class FRIENDS_EXPORT Friends : public CopyableWidget
{
    Q_OBJECT
public:
    Friends(DataBase *database, QWidget *parent = nullptr);
    ~Friends();

    CopyableWidget * copy() override;

    void setProperty(QString property, QList<QString> &list);

    void setUpFriends(QList<UserFriends> friends);

    void setUpBlocked(QList<UserBlocked> blocked);

    void setUpPending(QList<UserInvites> pending);

    void setUpReceive(QList<UserInvites> receives);

    void setUpInviteCode(QString inviteCode);

    void setUpProgileImage(QString imageUrl);

    void setUpName(QString nickname);

    void makeConnection();

    template <typename T>
    QVariantList toVariantList(const QList<T> &list);

private:
    Ui::Friends *ui;

    QObject *obj; //this is root object of qtquickview

    DataBase *database;


private slots:
    void getFriendsSlot();

    void getPendingSlot();

    void getReceiveSlot();

    void getBlockedSlot();
};

#endif // FRIENDS_H
