#include "game.h"
#include "ui_gamepage.h"

GamePage::GamePage(DataBase *database, QWidget *parent) : QWidget(parent), ui(new Ui::GamePage), database(database)
{
    ui->setupUi(this);
    ui->quickGamePageWidget->setSource(QUrl(QStringLiteral("qrc:/gamePage.qml")));
    this->obj = ui->quickGamePageWidget->rootObject();
    this->makeconnection();
}

GamePage::~GamePage()
{
    delete ui;
}

void GamePage::setGame(QString gameName)
{
    this->setGame(this->database->getGameQuery()->getGameByName(gameName));
}

void GamePage::setGame(Game game)
{
    this->gameName = game.title;
    this->insertGame(game);
    this->makeGamePlayable();
}

void GamePage::openHubPage(QString gameName)
{
    Hub *hub = new Hub(database, qobject_cast<QWidget*>(this->parent()));
    hub->setUpHub(database->getHubQuery()->getGameHub(gameName));
    hub->loadQmlHub();
    hub->show();
    this->deleteLater();
}

void GamePage::insertGame(Game game)
{
    QMetaObject::invokeMethod(obj, "setGame",
                              Q_ARG(QVariant, QVariant::fromValue(game.toVariantMap())));
}

void GamePage::makeGamePlayable()
{
    if(this->database->getUserQuery()->hasGame(gameName, "keyvan")){
        QMetaObject::invokeMethod(obj, "makeGamePlayable");
    }
}

void GamePage::makeconnection()
{
    QObject::connect(obj, SIGNAL(openHubPage(QString)), this, SLOT(openHubPage(QString)));
}
