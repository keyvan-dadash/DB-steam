#ifndef GAMECARD_H
#define GAMECARD_H

#include <QObject>
#include <QWidget>

class GameCard : public QWidget
{
    Q_OBJECT
public:
    explicit GameCard(QWidget *parent = nullptr);

signals:

};

#endif // GAMECARD_H
