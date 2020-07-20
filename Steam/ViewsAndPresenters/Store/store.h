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


#include "../../DataBase/models.h"
#include "database.h"
#include "game.h"
#include "../../Steam/copyablewidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Store; }
QT_END_NAMESPACE


class STORE_EXPORT Store : public CopyableWidget
{
    Q_OBJECT
public:
    enum MainView {
        featuredGames,
        newGames,
        topGames,
        topSales
    };

    Store(DataBase *database, int view = 0, QWidget *parent = nullptr);
    ~Store();

    CopyableWidget * copy() override;

    template <typename T>
    QVariantList toVariantList(const QList<T> &list);

    void setGames(QList<Game> &games);

    void setUpFeatureGamesView(QList<Game> games);

    void setUpTop100GamesView(QList<Game> games);

    void setUpNewGamesView(QList<Game> games);

public slots:
    void openGamePage(QString gameName);

private slots:
    void storeChangeItem(int item);

    void gameChangeItem(int item);

private:
    Ui::Store *ui;

    QObject *obj;

    DataBase *database;

    int view = 0;

    void makeConnection();
};

#endif // STORE_H
