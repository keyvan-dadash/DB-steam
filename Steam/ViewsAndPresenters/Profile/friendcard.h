#ifndef FRIENDCARD_H
#define FRIENDCARD_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class FriendCard : public QWidget
{
    Q_OBJECT
public:
    explicit FriendCard(QWidget *parent = nullptr);

    explicit FriendCard(QWidget *parent, QString profileImagePath, QString profileName, QString lastSeen);

private:
    QLabel *labelProfileImg = new QLabel();
    QLabel *labelName = new QLabel();
    QLabel *labelLastOnline = new QLabel();
    void styleLabelProfileImg(QString path);
    void styleLabelName(QString name);
    void styleLabelLastOnline(QString lastSeen);
signals:

};

#endif // FRIENDCARD_H
