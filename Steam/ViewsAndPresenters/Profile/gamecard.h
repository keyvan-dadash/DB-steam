#ifndef GAMECARD_H
#define GAMECARD_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QRandomGenerator>

class GameCard : public QWidget
{
    Q_OBJECT
public:
    explicit GameCard(QWidget *parent = nullptr);

    explicit GameCard(QWidget *parent, QString gameImagePath, QString gamePlayHours, QString gameName, QString lastTimePlayed);

    QString getGameName();

private:
    QLabel *labelHours = new QLabel();

    QLabel *labelLastPlayed = new QLabel();

    QPushButton *btnGame = new QPushButton();

    QLabel *labelGameImg = new QLabel();

    void styleBtnGame(QString gameName);

    void styleLabelHours(QString gamePlayHours);

    void styleLabelLastPlayed(QString lastTimePlayed);

    void styleLabelGameImg(QString path);

    void widgetStyle();

signals:

};

#endif // GAMECARD_H
