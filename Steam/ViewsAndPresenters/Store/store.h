#ifndef STORE_H
#define STORE_H

#include "Store_global.h"
#include <QWidget>
#include <QQmlContext>
#include <QVariantList>
#include <QVariantMap>
#include <QQuickItem>
#include <QQuickView>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class Store; }
QT_END_NAMESPACE


class STORE_EXPORT Store : public QWidget
{
    Q_OBJECT
public:
    Store(QWidget *parent = nullptr);
    ~Store();

    struct Game
    {
        QString title;
        //QString date_of_publish;
        QString description;
        //QString likes;
        //QString dislikes;
        //QString attr;
        QString price;
        //QString update_id;
        //QString number_of_purchase;
        QList<QString> images;
    };

    QVariantMap gameToVariantMap(Game game);

    template <typename T>
    QVariantList toVariantList(const QList<T> &list);

    void setGames(QList<Game> &games);

    void setUpFeatureGamesView(QList<Game> games);

    void setUpTop100GamesView(QList<Game> games);

    private:
        Ui::Store *ui;
        QObject *obj;
};

#endif // STORE_H
