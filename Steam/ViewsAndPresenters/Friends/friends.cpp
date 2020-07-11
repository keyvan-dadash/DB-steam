#include "friends.h"
#include "ui_friends.h"

Friends::Friends(QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Friends)
{
    ui->setupUi(this);
    ui->quickWidgetFriends->setSource(QUrl(QStringLiteral("qrc:/friendMain.qml")));


    this->obj = ui->quickWidgetFriends->rootObject(); //get root object of qtquick

    this->setUpFriends(QList<QString>{"hallo", "ali", "amir"}, QList<QString>{"2 days", "5 days", "3 days"});

    this->setUpBlocked(QList<QString>{"hallo1", "ali1", "amir1"}, QList<QString>{"12 days", "4 days", "1 days"});

    this->setUpPending(QList<QString>{"hallo2", "ali2", "amir2"}, QList<QString>{"1 days", "online", "2 days"});

    this->setUpReceive(QList<QString>{"hallo3", "ali3", "amir3"}, QList<QString>{"20 days", "15 days", "30 days"});

    this->setUpInviteCode("8529847");
}

Friends::~Friends()
{
    delete ui;
}

CopyableWidget *Friends::copy()
{
    return new Friends();
}

void Friends::setProperty(QString property, QList<QString> &list) //we must delete this method
{
    obj->setProperty(property.toUtf8().constData(), toVariantList(list));
}

void Friends::setUpFriends(QList<QString> frinedList, QList<QString> lastOnlineList)
{
    this->setProperty("friendNames", frinedList);
    this->setProperty("friendLastOnlineTime", lastOnlineList);
}

void Friends::setUpBlocked(QList<QString> blockedList, QList<QString> lastOnlineList)
{
    this->setProperty("blockedNames", blockedList);
    this->setProperty("blockedLastOnlineTime", lastOnlineList);
}

void Friends::setUpPending(QList<QString> pendingList, QList<QString> lastOnlineList)
{
    this->setProperty("pendingNames", pendingList);
    this->setProperty("pendingLastOnlineTime", lastOnlineList);
}

void Friends::setUpReceive(QList<QString> receiveList, QList<QString> lastOnlineList)
{
    this->setProperty("receiveNames", receiveList);
    this->setProperty("receiveLastOnlineTime", lastOnlineList);
}

void Friends::setUpInviteCode(QString inviteCode)
{
    this->obj->setProperty("inviteCode", QVariant(inviteCode));
}

template <typename T>
QVariantList Friends::toVariantList( const QList<T> &list )
{
    QVariantList newList;
    foreach( const T &item, list )
        newList << item;

    return newList;
}
