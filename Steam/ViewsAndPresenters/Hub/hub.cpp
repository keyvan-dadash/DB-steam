#include "hub.h"
#include "ui_hub.h"

Hub::Hub(DataBase *database, QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Hub), database(database)
{
    ui->setupUi(this);
    ui->quickWidgetHub->setSource(QUrl(QStringLiteral("qrc:/hubMain.qml")));

    this->obj = ui->quickWidgetHub->rootObject();
    this->makeConnection();
}

Hub::~Hub()
{
    delete ui;
}

CopyableWidget *Hub::copy()
{
    return new Hub(database);
}

void Hub::makeConnection()
{
    QObject::connect(obj, SIGNAL(getHub(QString)), this, SLOT(getHub(QString)));
    QObject::connect(obj, SIGNAL(getDiscussions(QString)), this, SLOT(getDiscussions(QString)));
    QObject::connect(obj, SIGNAL(getNews(QString)), this, SLOT(getNews(QString)));
    QObject::connect(obj, SIGNAL(getVideos(QString)), this, SLOT(getVideos(QString)));
}

void Hub::setUpHub(HubStruct hub)
{
    QMetaObject::invokeMethod(obj, "setHub",
                              Q_ARG(QVariant, QVariant::fromValue(hub.toVariantMap())));
}

void Hub::setUpDiscussions(QList<Discussion> discussions)
{
    QVariantList discussionList;
    foreach(Discussion discussion, discussions) {
        discussionList.push_back(discussion.toVariantMap());
    }

    QMetaObject::invokeMethod(obj, "setDiscussionArray",
                              Q_ARG(QVariant, QVariant::fromValue(discussionList)));
}

void Hub::setUpNews(QList<News> news)
{
    QVariantList newsList;
    foreach(News newsObj, news) {
        newsList.push_back(newsObj.toVariantMap());
    }

    QMetaObject::invokeMethod(obj, "setNewsArray",
                              Q_ARG(QVariant, QVariant::fromValue(newsList)));
}

void Hub::setUpVideos(QList<Video> videos)
{
    QVariantList videoList;
    foreach(Video video, videos) {
        videoList.push_back(video.toVariantMap());
    }

    QMetaObject::invokeMethod(obj, "setVideosArray",
                              Q_ARG(QVariant, QVariant::fromValue(videoList)));
}

void Hub::getHub(QString hubName)
{
    this->setUpHub(database->getHubQuery()->getHubByName("Midnight club"));
}

void Hub::getDiscussions(QString hubName)
{
    this->setUpDiscussions(database->getHubQuery()->getHubDiscussions("Midnight club"));
}

void Hub::getNews(QString hubName)
{
    this->setUpNews(database->getHubQuery()->getHubNews("Midnight club"));
}

void Hub::getVideos(QString hubName)
{
    this->setUpVideos(database->getHubQuery()->getHubVideos("Midnight club"));
}
