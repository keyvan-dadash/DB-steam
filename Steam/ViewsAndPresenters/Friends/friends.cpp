#include "friends.h"
#include "ui_friends.h"

Friends::Friends(DataBase *database, QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Friends), database(database)
{
    ui->setupUi(this);
    ui->quickWidgetFriends->setSource(QUrl(QStringLiteral("qrc:/friendMain.qml")));


    this->obj = ui->quickWidgetFriends->rootObject(); //get root object of qtquick

    this->makeConnection();

    User user = database->getUserQuery()->getUser(this->database->username);

    this->setUpInviteCode(user.inviteCode);
    this->setUpProgileImage(user.profileImg.url);
    this->setUpName(user.nickname);
}

Friends::~Friends()
{
    delete ui;
}

CopyableWidget *Friends::copy()
{
    return new Friends(database);
}

void Friends::setProperty(QString property, QList<QString> &list) //we must delete this method
{
    obj->setProperty(property.toUtf8().constData(), toVariantList(list));
}

void Friends::setUpFriends(QList<UserFriends> friends)
{

    QVariantList friendList;
    foreach(UserFriends userFriend, friends) {
        friendList.push_back(userFriend.toVariantMap());
    }
    QMetaObject::invokeMethod(obj, "setObjectsArray",
                              Q_ARG(QVariant, QVariant::fromValue(1)),
                              Q_ARG(QVariant, QVariant::fromValue(friendList)));
}

void Friends::setUpBlocked(QList<UserBlocked> blocked)
{
    QVariantList blockList;
    foreach(UserBlocked userBlocked, blocked) {
        blockList.push_back(userBlocked.toVariantMap());
    }
    QMetaObject::invokeMethod(obj, "setObjectsArray",
                              Q_ARG(QVariant, QVariant::fromValue(2)),
                              Q_ARG(QVariant, QVariant::fromValue(blockList)));
}

void Friends::setUpPending(QList<UserInvites> pending)
{
    QVariantList pendingList;
    foreach(UserInvites userInvite, pending) {
        pendingList.push_back(userInvite.toVariantMap());
    }
    QMetaObject::invokeMethod(obj, "setObjectsArray",
                              Q_ARG(QVariant, QVariant::fromValue(3)),
                              Q_ARG(QVariant, QVariant::fromValue(pendingList)));
}

void Friends::setUpReceive(QList<UserInvites> receives)
{
    QVariantList receiveList;
    foreach(UserInvites userInvite, receives) {
        receiveList.push_back(userInvite.toVariantMap());
    }
    QMetaObject::invokeMethod(obj, "setObjectsArray",
                              Q_ARG(QVariant, QVariant::fromValue(4)),
                              Q_ARG(QVariant, QVariant::fromValue(receiveList)));
}

void Friends::setUpInviteCode(QString inviteCode)
{
    this->obj->setProperty("inviteCode", QVariant(inviteCode));
}

void Friends::setUpProgileImage(QString imageUrl)
{
    this->obj->setProperty("imageUrl", QVariant(imageUrl));
}

void Friends::setUpName(QString nickname)
{
    this->obj->setProperty("name", QVariant(nickname));
}

void Friends::makeConnection()
{
    QObject::connect(obj, SIGNAL(getFriends()), this, SLOT(getFriendsSlot()));
    QObject::connect(obj, SIGNAL(getBlocked()), this, SLOT(getBlockedSlot()));
    QObject::connect(obj, SIGNAL(getPending()), this, SLOT(getPendingSlot()));
    QObject::connect(obj, SIGNAL(getReceive()), this, SLOT(getReceiveSlot()));
}

void Friends::getFriendsSlot()
{
    this->setUpFriends(this->database->getUserQuery()->getUserFriends(this->database->username));
}

void Friends::getPendingSlot()
{
    this->setUpPending(this->database->getUserQuery()->getUserPending(this->database->username));
}

void Friends::getReceiveSlot()
{
    this->setUpReceive(this->database->getUserQuery()->getUserReceive(this->database->username));
}

void Friends::getBlockedSlot()
{
    this->setUpBlocked(this->database->getUserQuery()->getUserBlocked(this->database->username));
}

template <typename T>
QVariantList Friends::toVariantList( const QList<T> &list )
{
    QVariantList newList;
    foreach( const T &item, list )
        newList << item;

    return newList;
}
