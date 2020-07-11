#ifndef FRIENDS_H
#define FRIENDS_H

#include "Friends_global.h"
#include <QWidget>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include <QList>

#include "../../Steam/copyablewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Friends; }
QT_END_NAMESPACE

class FRIENDS_EXPORT Friends : public CopyableWidget
{
    Q_OBJECT
public:
    Friends(QWidget *parent = nullptr);
    ~Friends();

    CopyableWidget * copy() override;

    void setProperty(QString property, QList<QString> &list);

    void setUpFriends(QList<QString> frinedList, QList<QString> lastOnlineList);

    void setUpBlocked(QList<QString> blockedList, QList<QString> lastOnlineList);

    void setUpPending(QList<QString> pendingList, QList<QString> lastOnlineList);

    void setUpReceive(QList<QString> receiveList, QList<QString> lastOnlineList);

    void setUpInviteCode(QString inviteCode);

    template <typename T>
    QVariantList toVariantList(const QList<T> &list);

private:
    Ui::Friends *ui;
    QObject *obj; //this is root object of qtquickview
};

#endif // FRIENDS_H
