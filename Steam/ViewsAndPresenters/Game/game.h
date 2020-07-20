#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include <QList>
#include <QDebug>
#include <QQmlEngine>

#include "Game_global.h"
#include "database.h"
#include "hub.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GamePage; }
QT_END_NAMESPACE

class GAME_EXPORT GamePage : public QWidget
{
    Q_OBJECT
public:
    GamePage(DataBase *database, QWidget *parent = nullptr);
    ~GamePage();

    void setGame(QString gameName);

    void setGame(Game game);

private slots:
    void openHubPage(QString gameName);

    void purchaseGame();

private:
    Ui::GamePage *ui;

    QObject *obj; //rootobject of qtquickview

    DataBase *database;

    QString gameName;

    void insertGame(Game game);

    void makeGamePlayable();

    void makeconnection();

};

#endif // GAME_H
