#ifndef MODELS_H
#define MODELS_H


#include <QString>
#include <QList>
#include <QVariantMap>
#include <QVariantList>
#include <QDebug>


struct File;
struct Game;
struct Company;
struct User;
struct UserFriends;
struct UserBlocked;
struct UserInvites;
struct News;
struct Discussion;
struct comment;
struct HubStruct;



struct File
{
    QString type;
    QString size;
    QString url;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("type", type);
        map.insert("size", size);
        map.insert("url", url);
        return map;
    }
};

struct Game
{
    QString title;
    QString date_of_publish;
    QString description;
    QString likes;
    QString dislikes;
    QString attr;
    QString price;
    QString update_id;
    QString number_of_purchase;
    QList<File> images;
    QString companyName;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("title", title);
        map.insert("date_of_publish", date_of_publish);
        map.insert("description", description);
        map.insert("likes", likes);
        map.insert("dislikes", dislikes);
        map.insert("attr", attr);
        map.insert("price", price);
        map.insert("update_id", update_id);
        map.insert("number_of_purchase", number_of_purchase);
        QVariantList files;
        foreach(File file, images) {
            files << file.toVariantMap();
        }
        map.insert("images", files);
        map.insert("company", companyName);
        return map;
    }
};

struct Company
{
    QString name;
    QString bio;
    QList<Game> games;
    File companyImage;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("name", name);
        map.insert("bio", bio);
        QVariantList gamesList;
        foreach(Game game, games) {
            gamesList << game.toVariantMap();
        }
        map.insert("games", gamesList);
        map.insert("companyImage", companyImage.toVariantMap());
        return map;
    }
};

struct User
{
    QString username;
    QString email;
    QString bio;
    QString level;
    QString wallet;
    QString last_time_online;
    QString nickname;
    QString inviteCode;
    QString birth;
    QList<Game> games;
    File profileImg;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("username", username);
        map.insert("email", email);
        map.insert("bio", bio);
        map.insert("level", level);
        map.insert("wallet", wallet);
        map.insert("last_time_online", last_time_online);
        map.insert("nickname", nickname);
        map.insert("inviteCode", inviteCode);
        map.insert("birth", birth);
        QVariantList gameList;
        foreach(Game game, games) {
            gameList << game.toVariantMap();
        }
        map.insert("games", gameList);
        map.insert("profileImg", profileImg.toVariantMap());
        return map;
    }
};

struct UserFriends : User {
    QString since;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("username", username);
        map.insert("email", email);
        map.insert("bio", bio);
        map.insert("level", level);
        map.insert("last_time_online", last_time_online);
        map.insert("nickname", nickname);
        map.insert("inviteCode", inviteCode);
        map.insert("birth", birth);
        map.insert("profileImg", profileImg.toVariantMap());
        map.insert("since", since);
        return map;
    }
};

struct UserBlocked : User {
    QString since;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("username", username);
        map.insert("nickname", nickname);
        map.insert("last_time_online", last_time_online);
        map.insert("since", since);
        return map;
    }
};

struct UserInvites : User {
    QString status;
    QString invite_date;
    QString sender_nickname;
    QString receiver_nickname;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("username", username);
        map.insert("nickname", nickname);
        map.insert("last_time_online", last_time_online);
        map.insert("since", status);
        map.insert("invite_date", invite_date);
        map.insert("sender_nickname", sender_nickname);
        map.insert("receiver_nickname", receiver_nickname);
        return map;
    }
};

struct News
{
    QString title;
    QString body;
    QString publish_date;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("title", title);
        map.insert("body", body);
        map.insert("publish_date", publish_date);
        return map;
    }
};

struct Discussion
{
    QString title;
    QString body;
    QString discussion_start_date;
    QString last_comment_date;
    QString last_comment_username;
    User author;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("title", title);
        map.insert("body", body);
        map.insert("discussion_start_date", discussion_start_date);
        map.insert("last_comment_date", last_comment_date);
        map.insert("last_comment_username", last_comment_username);
        map.insert("author", author.toVariantMap());
        return map;
    }
};

struct comment
{
    QString type;
    QString body;
    QString sent_date;
    User user_comment;
    Discussion discussion;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("type", type);
        map.insert("body", body);
        map.insert("sent_date", sent_date);
        map.insert("user_comment", user_comment.toVariantMap());
        map.insert("discussion", discussion.toVariantMap());
        return map;
    }
};

struct HubStruct
{
    QString name;
    QString description;
    Game game;
    QList<QString> videosPath;
    QList<Discussion> discussions;
    QList<News> news;

    QVariantMap toVariantMap() {
        QVariantMap map;
        map.insert("name", name);
        map.insert("description", description);
        map.insert("game", game.toVariantMap());
        QVariantList videosPathList;
        foreach(QString path, videosPath) {
            videosPath << path;
        }
        map.insert("videosPath", videosPathList);
        QVariantList discussionsList;
        foreach(Discussion discussion, discussions) {
            discussionsList << discussion.toVariantMap();
        }
        map.insert("discussions", discussionsList);
        QVariantList newsList;
        foreach(News lNews, news) {
            newsList << lNews.toVariantMap();
        }
        map.insert("news", newsList);
        return map;
    }
};


#endif // MODELS_H
