#include "hub.h"
#include "ui_hub.h"

Hub::Hub(DataBase *database, QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Hub), database(database)
{
    ui->setupUi(this);
    this->styleListWidgetsAndScrollBar();
    ui->quickWidgetHub->resize(this->width(), this->height());
    ui->quickWidgetHub->setSource(QUrl(QStringLiteral("qrc:/hubMain.qml")));
    this->obj = ui->quickWidgetHub->rootObject();
    this->makeConnection();
    this->listWidgetConnections();

    this->stackSbilingWidget(ui->scrollArea, ui->quickWidgetHub);

    for (int i = 0; i < 50; i++) {
        addCard("Midnight club", "sfsdfss", "ssffs", ui->listWidgetPopular);
    }
    ui->resultListWidget->resize(ui->resultListWidget->width(), 50 * 52);
    ui->scrollArea->widget()->adjustSize();

    this->showResult("sf");
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

void Hub::listWidgetConnections()
{
    QObject::connect(ui->listWidgetPopular, &QListWidget::itemClicked, this, &Hub::setUpHubQmlFromPopular);
    QObject::connect(ui->listWidgetRecentViewed, &QListWidget::itemClicked, this, &Hub::setUpHubQmlFromRecentList);
    QObject::connect(ui->resultListWidget, &QListWidget::itemClicked, this, &Hub::setUpHubQmlFromResult);
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
    this->setUpHub(database->getHubQuery()->getHubByName(hubName));
}

void Hub::getDiscussions(QString hubName)
{
    this->setUpDiscussions(database->getHubQuery()->getHubDiscussions(hubName));
}

void Hub::getNews(QString hubName)
{
    this->setUpNews(database->getHubQuery()->getHubNews(hubName));
}

void Hub::getVideos(QString hubName)
{
    this->setUpVideos(database->getHubQuery()->getHubVideos(hubName));
}

void Hub::setUpHubQmlFromPopular(QListWidgetItem *item)
{
    HubCard *hubcard = qobject_cast<HubCard *>(ui->listWidgetPopular->itemWidget(item));
    this->getHub(hubcard->getHubName());
    this->loadQmlHub();
}

void Hub::setUpHubQmlFromResult(QListWidgetItem *item)
{
    HubCard *hubcard = qobject_cast<HubCard *>(ui->listWidgetRecentViewed->itemWidget(item));
    this->getHub(hubcard->getHubName());
    this->loadQmlHub();
}

void Hub::setUpHubQmlFromRecentList(QListWidgetItem *item)
{
    ResultCard *resultcard = qobject_cast<ResultCard *>(ui->resultListWidget->itemWidget(item));
    this->getHub(resultcard->getHubName());
    this->loadQmlHub();
}

void Hub::loadQmlHub()
{
    this->stackSbilingWidget(ui->quickWidgetHub, ui->scrollArea);
}

void Hub::stackSbilingWidget(QWidget *top, QWidget *bottom)
{
    bottom->stackUnder(top);
}

void Hub::addCard(QString hubName, QString numberOfRecentDiscussion, QString imagePath, QListWidget *listwidget)
{
    HubCard *hcard = new HubCard();
    hcard->setHubName(hubName);
    hcard->setNumberOfRecentDiscussion(numberOfRecentDiscussion);
    hcard->setHubImage(imagePath);
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(hcard->width(), hcard->height()));
    listwidget->addItem(item);
    listwidget->setItemWidget(item, hcard);
}

void Hub::addResultCard(QString title, QString extra, QString imagePath, QListWidget *listwidget)
{
    ResultCard *rcard = new ResultCard();
    rcard->setTitle(title);
    rcard->setExtraAttribute(extra);
    rcard->setImg(imagePath);
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(rcard->width(), rcard->height()));
    listwidget->addItem(item);
    listwidget->setItemWidget(item, rcard);
}

void Hub::styleListWidgetsAndScrollBar()
{
    ui->listWidgetPopular->horizontalScrollBar()->setVisible(false);
    ui->listWidgetPopular->verticalScrollBar()->setVisible(false);
    ui->listWidgetRecentViewed->horizontalScrollBar()->setVisible(false);
    ui->listWidgetRecentViewed->verticalScrollBar()->setVisible(false);
    ui->resultListWidget->horizontalScrollBar()->setVisible(false);
    ui->resultListWidget->verticalScrollBar()->setVisible(false);
    ui->scrollArea->setWidgetResizable(false);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Hub::showResult(QString resultLabelText)
{
    ui->resultLabel->setText(resultLabelText);
    ui->resultLabel->setEnabled(true);
    ui->resultLabel->setVisible(true);
    ui->resultListWidget->setEnabled(true);
    ui->resultListWidget->setVisible(true);
    ui->dividerResultLabel->setEnabled(true);
    ui->dividerResultLabel->setVisible(true);
}

void Hub::hideResult()
{
    ui->resultLabel->setEnabled(false);
    ui->resultLabel->setVisible(false);
    ui->resultListWidget->setEnabled(false);
    ui->resultListWidget->setVisible(false);
    ui->dividerResultLabel->setEnabled(false);
    ui->dividerResultLabel->setVisible(false);
}
