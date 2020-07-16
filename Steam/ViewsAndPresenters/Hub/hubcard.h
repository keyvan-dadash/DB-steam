#ifndef HUBCARD_H
#define HUBCARD_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRandomGenerator>
#include <QDebug>


class HubCard : public QWidget
{
    Q_OBJECT
public:
    explicit HubCard(QWidget *parent = nullptr);

    void setHubName(QString hubName);

    void setNumberOfRecentDiscussion(QString discussionCount);

    void setHubImage(QString path);

    QString getHubName();

signals:

private:
    QLabel *qlabelName = new QLabel();

    QLabel *qlabelTopicsCount = new QLabel();

    QLabel *qlabelHubImg = new QLabel();
};

#endif // HUBCARD_H
