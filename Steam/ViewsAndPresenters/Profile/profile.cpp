#include "profile.h"
#include "ui_profile.h"


Profile::Profile(DataBase *database, QWidget *parent) :
    CopyableWidget(parent), ui(new Ui::Profile), database(database)
{
    ui->setupUi(this);
    User user = database->getUserQuery()->getUser("keyvan");
    this->setName(user.username);
    this->setLevel(user.level);
    this->setBio(user.bio);
    this->setLastOnlineTime(user.last_time_online);
    this->setProfileImage(user.profileImg.url);

    this->filterUserFriends(database->getUserQuery()->getUserFriends("keyvan"));
    this->filterUserGames(database->getUserQuery()->getUserGames("keyvan"));
    this->makeConnection();
}

Profile::~Profile()
{
    delete ui;
}

CopyableWidget *Profile::copy()
{
    return new Profile(database);
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

void Profile::filterUserGames(QList<Game> gameList)
{
    std::sort(gameList.begin(), gameList.end(), [](Game &g1, Game &g2){
        return g1.number_of_purchase < g2.number_of_purchase;
    });

    for(int i = 0; i < 3; i++ ){
        this->addGameCard("sfs", gameList[i].number_of_purchase, gameList[i].title, gameList[i].price);
    }
}

void Profile::filterUserFriends(QList<UserFriends> friendList)
{
    std::sort(friendList.begin(), friendList.end(), [](UserFriends &uf1, UserFriends &uf2)
    {
        return uf2.last_time_online < uf1.last_time_online;
    });

    for(int i = 0; i < 3; i++ ){
        this->addFriendCrad("sfs", friendList[i].username, friendList[i].last_time_online);
    }
}

void Profile::openGamePage(QListWidgetItem *item)
{
    GameCard *gamecard = qobject_cast<GameCard*>(ui->listGames->itemWidget(item));
    GamePage *gamepage = new GamePage(database, qobject_cast<QWidget*>(this->parent()));
    gamepage->setGame(gamecard->getGameName());
    gamepage->show();
    this->deleteLater();
}

void Profile::makeConnection()
{
    QObject::connect(ui->listGames, &QListWidget::itemClicked, this, &Profile::openGamePage);
}
