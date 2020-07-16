#include "hubquery.h"

HubQuery::HubQuery()
{

}

int HubQuery::getHubId(QString hubName)
{
    QSqlQuery hubQ;
    hubQ.prepare("select id from hub where name = :name;");
    hubQ.bindValue(":name", hubName);
    hubQ.exec();
    qInfo() << hubQ.executedQuery();
    return hubQ.value(0).toInt();
}

HubStruct HubQuery::getHubByName(QString hubName)
{
    QSqlQuery hubQ;
    hubQ.prepare("select game.title, game.date_of_publish, game.likes, game.dislikes, game.price, game.number_of_purchase,"
                 " hub.* from hub left join game on game.id = hub.game_id where hub.name = :name;");
    hubQ.bindValue(":name", hubName);
    hubQ.exec();
    qInfo() << hubQ.executedQuery();
    QSqlQueryModel model;
    model.setQuery(hubQ);
    return this->toHub(model.record(0));
}

HubStruct HubQuery::getGameHub(QString gameName)
{
    QSqlQuery hubQ;
    hubQ.prepare("select game.title, game.date_of_publish, game.likes, game.dislikes, game.price, game.number_of_purchase, hub.* from hub"
                 " left join game on game.id = hub.game_id where game.title = :name;");
    hubQ.bindValue(":name", gameName);
    hubQ.exec();
    qInfo() << hubQ.executedQuery();
    QSqlQueryModel model;
    model.setQuery(hubQ);
    return this->toHub(model.record(0));
}

QList<Discussion> HubQuery::getHubDiscussions(QString hubName)
{
    QSqlQuery discussionQ;
    discussionQ.prepare("with discussions as ("
                        " select * from discussion left join hub on hub.id = discussion.hub_id where hub.name = :name"
                        " )"
                        " select discussions.*, users.nickname from discussions left join users on users.id = discussions.author_id;");
    discussionQ.bindValue(":name", hubName);
    discussionQ.exec();
    qInfo() << discussionQ.executedQuery();
    QList<Discussion> discussions;
    QSqlQueryModel model;
    model.setQuery(discussionQ);
    for(int i = 0; i < model.rowCount(); i++) {
        discussions.push_back(this->toDiscussion(model.record(i)));
    }
    return discussions;
}

QList<News> HubQuery::getHubNews(QString hubName)
{
    QSqlQuery newsQ;
    newsQ.prepare("select * from news left join hub on hub.id = news.hub_id where hub.name = :name;");
    newsQ.bindValue(":name", hubName);
    newsQ.exec();
    qInfo() << newsQ.executedQuery();
    QList<News> news;
    QSqlQueryModel model;
    model.setQuery(newsQ);
    for(int i = 0; i < model.rowCount(); i++) {
        news.push_back(this->toNews(model.record(i)));
    }
    return news;
}

QList<Video> HubQuery::getHubVideos(QString hubName)
{
    QSqlQuery videoQ;
    videoQ.prepare("select * from videos left join file on file.id = videos.file_id where"
                  " videos.hub_id = (select id from hub where hub.name = :name);");
    videoQ.bindValue(":name", hubName);
    videoQ.exec();
    qInfo() << videoQ.executedQuery();
    QList<Video> videos;
    QSqlQueryModel model;
    model.setQuery(videoQ);
    for(int i = 0; i < model.rowCount(); i++) {
        videos.push_back(this->toVideos(model.record(i)));
    }
    return videos;
}

QList<Comment> HubQuery::getDiscussionComments(int discussionId)
{
    QSqlQuery commentQ;
    commentQ.prepare("with discussionCommens as ("
                     " select comment.* from comment left join discussion on"
                     " discussion.id = comment.discussion_id where comment.discussion_id = :id"
                     " )"
                     " select discussionCommens.*, users.nickname from discussionCommens left join users on users.id = discussionCommens.sender_id;");
    commentQ.bindValue(":id", discussionId);
    commentQ.exec();
    qInfo() << commentQ.executedQuery();
    QList<Comment> comments;
    QSqlQueryModel model;
    model.setQuery(commentQ);
    for(int i = 0; i < model.rowCount(); i++) {
        comments.push_back(this->toComment(model.record(i)));
    }
    return comments;
}

QList<HubStruct> HubQuery::getPopularHub()
{
    QSqlQuery hubQ;
    hubQ.prepare("select D.discussionCount, hub.* from (select id, count(*) as discussionCount from (select hub.* from discussion"
                 " left join hub on hub.id = discussion.hub_id where discussion.start_time > NOW() - INTERVAL '5 Year')"
                 " as lastDiscussion group by id) as D left join hub on D.id = hub.id order by D.discussionCount desc limit 10;");
    hubQ.exec();
    qInfo() << hubQ.executedQuery();
    QSqlQueryModel model;
    model.setQuery(hubQ);
    QList<HubStruct> hubs;
    for(int i = 0; i < model.rowCount(); i++) {
        HubStruct hubS = this->toOnlyHub(model.record(i));
        hubS.numberOfDiscussions = model.record(i).value("discussioncount").toInt();
        hubs.push_back(hubS);
    }
    return hubs;
}

QList<HubStruct> HubQuery::getUserLastActivity(QString username)
{
    QSqlQuery hubQ;
    hubQ.prepare("select hub.*, sent_date from ((select users.username, comment.discussion_id, comment.sent_date  from comment left join users on comment.sender_id = users.id) as comments left join"
                 " discussion on comments.discussion_id = discussion.id) as discussion_comment left join hub on hub.id = discussion_comment.hub_id"
                 " where username = :username order by sent_date desc limit 10;");
    hubQ.bindValue(":username", username);
    hubQ.exec();
    qInfo() << hubQ.executedQuery();
    QSqlQueryModel model;
    model.setQuery(hubQ);
    QList<HubStruct> hubs;
    for(int i = 0; i < model.rowCount(); i++) {
        HubStruct hubS = this->toOnlyHub(model.record(i));
        hubS.description = model.record(i).value("sent_date").toString();
        hubs.push_back(hubS);
    }
    return hubs;
}

QList<HubStruct> HubQuery::getHubsBySimilarity(QString hubName)
{
    QSqlQuery hubQ;
    hubQ.prepare("select * from (select hub.*, similarity(name, :name) as sm from hub order by sm desc)"
                 " as similarity where similarity.sm > 0.005 limit 50;");
    hubQ.bindValue(":name", hubName);
    hubQ.exec();
    qInfo() << hubQ.executedQuery();
    QSqlQueryModel model;
    model.setQuery(hubQ);
    QList<HubStruct> hubs;
    for(int i = 0; i < model.rowCount(); i++) {
        HubStruct hubS = this->toOnlyHub(model.record(i));
        hubs.push_back(hubS);
    }
    return hubs;
}

QList<Discussion> HubQuery::getDiscussionBySimilarity(QString discussionTitle)
{
    QSqlQuery discussionQ;
    discussionQ.prepare("select * from (select discussion.*, similarity(title, :title) as sm from discussion order by sm desc)"
                 " as similarity where similarity.sm > 0.005 limit 50;");
    discussionQ.bindValue(":title", discussionTitle);
    discussionQ.exec();
    qInfo() << discussionQ.executedQuery();
    QSqlQueryModel model;
    model.setQuery(discussionQ);
    QList<Discussion> discussions;
    for(int i = 0; i < model.rowCount(); i++) {
        discussions.push_back(this->toDiscussion(model.record(i)));
    }
    return discussions;
}

HubStruct HubQuery::toHub(QSqlRecord hubQ)
{
    HubStruct hub;
    hub.game.title = hubQ.value("title").toString();
    hub.game.date_of_publish = hubQ.value("date_of_publish").toString();
    hub.description = hubQ.value("description").toString();
    hub.game.likes = hubQ.value("likes").toString();
    hub.game.dislikes = hubQ.value("dislikes").toString();
    hub.name = hubQ.value("name").toString();
    hub.game.price = hubQ.value("price").toString();
    hub.game.number_of_purchase = hubQ.value("number_of_purchase").toString();
    hub.numberOfDiscussions = this->getHubDiscussionsCount(hubQ.value("id").toInt());
    hub.numberOfNews = this->getHubNewsCount(hubQ.value("id").toInt());
    return hub;
}

HubStruct HubQuery::toOnlyHub(QSqlRecord hubQ)
{
    HubStruct hub;
    hub.description = hubQ.value("description").toString();
    hub.name = hubQ.value("name").toString();
    return hub;
}

Discussion HubQuery::toDiscussion(QSqlRecord discussionQ)
{
    Discussion discussion;
    discussion.title = discussionQ.value("title").toString();
    discussion.body = discussionQ.value("body").toString();
    discussion.author.nickname = discussionQ.value("nickname").toString();
    discussion.discussion_start_date = discussionQ.value("start_time").toString();
    discussion.last_comment_date = discussionQ.value("last_comment_time").toString();
    discussion.last_comment_nickname = discussionQ.value("last_comment_nickname").toString();
    return discussion;
}

News HubQuery::toNews(QSqlRecord newsQ)
{
    News news;
    news.title = newsQ.value("title").toString();
    news.body = newsQ.value("body").toString();
    news.publish_date = newsQ.value("publishdate").toString();
    return news;
}

Video HubQuery::toVideos(QSqlRecord videosQ)
{
    Video video;
    video.size = videosQ.value("size").toString();
    video.type = videosQ.value("type").toString();
    video.url = videosQ.value("file_url").toString();
    video.name = videosQ.value("name").toString();
    video.likes = videosQ.value("likes").toInt();
    return video;
}

Comment HubQuery::toComment(QSqlRecord commentQ)
{
    Comment comment;
    comment.body = commentQ.value("body").toString();
    comment.type = commentQ.value("type").toString();
    comment.sent_date = commentQ.value("sent_date").toString();
    comment.user_comment.nickname = commentQ.value("nickname").toString();
    return comment;
}

int HubQuery::getHubDiscussionsCount(int hubId)
{
    QSqlQuery hubQ;
    hubQ.prepare("select count(*) from discussion where hub_id = :id;");
    hubQ.bindValue(":id", hubId);
    hubQ.exec();
    qInfo() << hubQ.executedQuery();
    QSqlQueryModel model;
    model.setQuery(hubQ);
    return model.record(0).value("count").toInt();
}

int HubQuery::getHubNewsCount(int hubId)
{
    QSqlQuery hubQ;
    hubQ.prepare("select count(*) from news where hub_id = :id;");
    hubQ.bindValue(":id", hubId);
    hubQ.exec();
    qInfo() << hubQ.executedQuery();
    QSqlQueryModel model;
    model.setQuery(hubQ);
    return model.record(0).value("count").toInt();
}
