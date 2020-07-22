#include "hub.h"
#include "ui_hub.h"

Hub::Hub(DataBase *database, QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Hub), database(database)
{
    ui->setupUi(this);
    this->styleListWidgetsAndScrollBar();
    this->hideResult();

    //fit quickwidget and get rootobject
    ui->quickWidgetHub->resize(this->width(), this->height());
    ui->quickWidgetHub->setSource(QUrl(QStringLiteral("qrc:/hubMain.qml")));
    this->obj = ui->quickWidgetHub->rootObject();

    //create connection between qml and hub and hub with listwidgets
    this->makeConnection();
    this->listWidgetConnections();

    //set scroll are on top of quickwidget
    this->stackSbilingWidget(ui->scrollArea, ui->quickWidgetHub);

    QList<HubStruct> hubs;
    hubs = database->getHubQuery()->getPopularHub();
    foreach(HubStruct hub, hubs) {
        this->addCard(hub.name, QString::number(hub.numberOfDiscussions), "sff", ui->listWidgetPopular);
    }

    hubs.clear();
    hubs = database->getHubQuery()->getUserLastActivity(this->database->username);
    foreach(HubStruct hub, hubs) {
        this->addCard(hub.name, hub.description, "sff", ui->listWidgetRecentViewed);
    }
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
    QObject::connect(obj, SIGNAL(getDiscussionsComments(int)), this, SLOT(getComments(int)));
    QObject::connect(obj, SIGNAL(openGamePage(QString)), this, SLOT(openGamePage(QString)));
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

void Hub::setUpComments(QList<Comment> comments)
{
    QVariantList commentList;
    foreach(Comment comment, comments) {
        commentList.push_back(comment.toVariantMap());
    }

    QMetaObject::invokeMethod(obj, "setCommetnsArray",
                              Q_ARG(QVariant, QVariant::fromValue(commentList)));
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

void Hub::getComments(int discussionId)
{
    this->setUpComments(database->getHubQuery()->getDiscussionComments(discussionId));
}

void Hub::setUpHubQmlFromPopular(QListWidgetItem *item)
{
    HubCard *hubcard = qobject_cast<HubCard *>(ui->listWidgetPopular->itemWidget(item));
    this->getHub(hubcard->getHubName());
    this->loadQmlHub();
}

void Hub::setUpHubQmlFromRecentList(QListWidgetItem *item)
{
    HubCard *hubcard = qobject_cast<HubCard *>(ui->listWidgetRecentViewed->itemWidget(item));
    this->getHub(hubcard->getHubName());
    this->loadQmlHub();
}

void Hub::setUpHubQmlFromResult(QListWidgetItem *item)
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

QListWidgetItem* Hub::addCard(QString hubName, QString numberOfRecentDiscussion, QString imagePath, QListWidget *listwidget)
{
    HubCard *hcard = new HubCard();
    hcard->setHubName(hubName);
    hcard->setNumberOfRecentDiscussion(numberOfRecentDiscussion);
    hcard->setHubImage(imagePath);
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(hcard->width(), hcard->height()));
    listwidget->addItem(item);
    listwidget->setItemWidget(item, hcard);
    return item;
}

QListWidgetItem* Hub::addResultCard(QString hubName, QString title, QString extra, QString imagePath, QListWidget *listwidget)
{
    ResultCard *rcard = new ResultCard();
    rcard->setTitle(title);
    rcard->setExtraAttribute(extra);
    rcard->setImg(imagePath);
    rcard->setHubName(hubName);
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(rcard->width(), rcard->height()));
    listwidget->addItem(item);
    listwidget->setItemWidget(item, rcard);
    return item;
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

void Hub::openGamePage(QString gameName)
{
    GamePage *gamepage = new GamePage(database, qobject_cast<QWidget*>(this->parent()));
    gamepage->setGame(gameName);
    gamepage->show();
    this->deleteLater();
}

void Hub::on_hubButton_clicked()
{
    ui->resultListWidget->clear();
    QList<HubStruct> hubs;
    int totalHeight = 0;
    hubs = database->getHubQuery()->getHubsBySimilarity(ui->hubSearchLine->text());
    foreach(HubStruct hub, hubs) {
        totalHeight += this->addResultCard(hub.name, hub.name, hub.description, "sff", ui->resultListWidget)->sizeHint().height();
    }
    ui->resultListWidget->resize(ui->resultListWidget->size().width(), totalHeight);
    this->showResult("List of related hubs");
    ui->scrollArea->widget()->adjustSize();
}

void Hub::on_discussionButton_clicked()
{
    ui->resultListWidget->clear();
    QList<Discussion> discussions;
    int totalHeight = 0;
    discussions = database->getHubQuery()->getDiscussionBySimilarity(ui->discussionSearchLine->text());
    foreach(Discussion discussion, discussions) {
        totalHeight += this->addResultCard(discussion.hubName, discussion.title, discussion.last_comment_date, "sff", ui->resultListWidget)->sizeHint().height();
    }
    ui->resultListWidget->resize(ui->resultListWidget->size().width(), totalHeight);
    this->showResult("List of related discussions");
    ui->scrollArea->widget()->adjustSize();
}
