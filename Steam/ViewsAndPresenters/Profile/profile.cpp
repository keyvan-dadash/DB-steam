#include "profile.h"
#include "ui_profile.h"


Profile::Profile(QWidget *parent) :
    CopyableWidget(parent), ui(new Ui::Profile)
{
    ui->setupUi(this);
}

Profile::~Profile()
{
    delete ui;
}

CopyableWidget *Profile::copy()
{
    return new Profile();
}

void Profile::setName(QString name)
{
    ui->nameLabel->setText(name);
}

void Profile::setLevel(QString level)
{
    ui->levelNumberLabel->setText(level);
}

void Profile::setBio(QString bio)
{
    ui->bioExLabel->setText(bio);
}

void Profile::setProfileImage(QString path)
{
    QPixmap img(path);
    int h = ui->profileImg->height();
    int w = ui->profileImg->width();
    ui->profileImg->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}

void Profile::setLastOnlineTime(QString lastTime)
{
    ui->lastOnlineLabel->setText(lastTime);
}

void Profile::setVisiableEditButton(bool visiable)
{
    ui->btnEditProfile->setVisible(visiable);
}

void Profile::addGameCard(QString gameImagePath, QString gamePlayHours, QString gameName, QString lastTimePlayed)
{
    GameCard *game = new GameCard(this, gameImagePath, gamePlayHours, gameName, lastTimePlayed);
    QListWidgetItem *list = new QListWidgetItem();
    list->setSizeHint(QSize(game->width(), game->height()));
    list->setBackground(QColor(0, 0, 0));
    ui->listGames->addItem(list);
    ui->listGames->setItemWidget(list, game);
}

void Profile::addFriendCrad(QString profileImagePath, QString profileName, QString lastSeen)
{
    FriendCard *friendcard = new FriendCard(this, profileImagePath, profileName, lastSeen);
    QListWidgetItem *list = new QListWidgetItem();
    list->setSizeHint(QSize(friendcard->width(), friendcard->height()));
    list->setBackground(QColor(0, 0, 0));
    ui->listFriend->addItem(list);
    ui->listFriend->setItemWidget(list, friendcard);
}
