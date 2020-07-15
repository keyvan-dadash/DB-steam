#ifndef HUBQUERY_H
#define HUBQUERY_H

#include <QList>
#include <QString>
#include <QtSql>

#include "HubQueryAbstract.h"
#include "models.h"



class HubQuery : public HubQueryAbstract
{
public:
    HubQuery();

    int getHubId(QString hubName) override;

    HubStruct getHubByName(QString hubName) override;

    HubStruct getGameHub(QString gameName) override;

    QList<Discussion> getHubDiscussions(QString hubName) override;

    QList<News> getHubNews(QString hubName) override;

    QList<Video> getHubVideos(QString hubName) override;

    QList<Comment> getDiscussionComments(int discussionId) override;

private:
    HubStruct toHub(QSqlRecord hubQ);

    Discussion toDiscussion(QSqlRecord discussionQ);

    News toNews(QSqlRecord newsQ);

    Video toVideos(QSqlRecord videosQ);

    Comment toComment(QSqlRecord commentQ);

    int getHubDiscussionsCount(int hubId);

    int getHubNewsCount(int hubId);
};

#endif // HUBQUERY_H
