#ifndef HUBQUERYABSTRACT_H
#define HUBQUERYABSTRACT_H




#include <QtSql>
#include <QList>

#include "models.h"


class HubQueryAbstract
{
public:
    virtual int getHubId(QString hubName) = 0;

    virtual HubStruct getHubByName(QString hubName) = 0;

    virtual HubStruct getGameHub(QString gameName) = 0;

    virtual QList<Discussion> getHubDiscussions(QString hubName) = 0;

    virtual QList<News> getHubNews(QString hubName) = 0;

    virtual QList<Video> getHubVideos(QString hubName) = 0;

    virtual QList<Comment> getDiscussionComments(int discussionId) = 0;

    virtual QList<HubStruct> getPopularHub() = 0;

    virtual QList<HubStruct> getUserLastActivity(QString username) = 0;

    virtual QList<HubStruct> getHubsBySimilarity(QString hubName) = 0;

    virtual QList<Discussion> getDiscussionBySimilarity(QString discussionTitle) = 0;
};

#endif // HUBQUERYABSTRACT_H
