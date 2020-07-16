#ifndef HUB_H
#define HUB_H

#include "Hub_global.h"
#include <QWidget>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include <QVariant>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QScrollArea>


#include "../../Steam/copyablewidget.h"
#include "database.h"
#include "hubcard.h"
#include "resultcard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Hub; }
QT_END_NAMESPACE

class HUB_EXPORT Hub : public CopyableWidget
{
    Q_OBJECT
public:
    Hub(DataBase *database, QWidget *parent = nullptr);
    ~Hub();

    CopyableWidget * copy() override;

    void makeConnection();

    void listWidgetConnections();

    void setUpHub(HubStruct hub);

    void setUpDiscussions(QList<Discussion> discussions);

    void setUpNews(QList<News> news);

    void setUpVideos(QList<Video> videos);

public slots:
    void getHub(QString hubName);

    void getDiscussions(QString hubName);

    void getNews(QString hubName);

    void getVideos(QString hubName);

    void setUpHubQmlFromPopular(QListWidgetItem *item);

    void setUpHubQmlFromResult(QListWidgetItem *item);

    void setUpHubQmlFromRecentList(QListWidgetItem *item);

private:
    Ui::Hub *ui;

    DataBase *database;

    QObject *obj;

    void loadQmlHub();

    void stackSbilingWidget(QWidget *top, QWidget *bottom);

    void addCard(QString hubName, QString numberOfRecentDiscussion, QString imagePath, QListWidget *listwidget);

    void addResultCard(QString title, QString extra, QString imagePath, QListWidget *listwidget);

    void styleListWidgetsAndScrollBar();

    void showResult(QString resultLabelText);

    void hideResult();
};

#endif // HUB_H
