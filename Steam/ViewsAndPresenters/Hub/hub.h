#ifndef HUB_H
#define HUB_H

#include "Hub_global.h"
#include <QWidget>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include <QVariant>


#include "../../Steam/copyablewidget.h"
#include "database.h"

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

    void setUpHub(HubStruct hub);

    void setUpDiscussions(QList<Discussion> discussions);

    void setUpNews(QList<News> news);

    void setUpVideos(QList<Video> videos);

public slots:
    void getHub(QString hubName);

    void getDiscussions(QString hubName);

    void getNews(QString hubName);

    void getVideos(QString hubName);

private:
    Ui::Hub *ui;

    DataBase *database;

    QObject *obj;
};

#endif // HUB_H
