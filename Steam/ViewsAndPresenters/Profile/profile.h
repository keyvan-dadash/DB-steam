#ifndef PROFILE_H
#define PROFILE_H

#include "Profile_global.h"
#include <QtWidgets>
#include <QList>
#include <QString>


#include "../../Steam/copyablewidget.h"
#include "gamecard.h"
#include "friendcard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Profile; }
QT_END_NAMESPACE


class PROFILE_EXPORT Profile : public CopyableWidget
{
    Q_OBJECT
public:
    Profile(QWidget *parent = nullptr);
    ~Profile();

    CopyableWidget * copy() override;

    void setName(QString name);

    void setLevel(QString level);

    void setBio(QString bio);

    void setProfileImage(QString path);

    void setLastOnlineTime(QString lastTime);

    void setVisiableEditButton(bool visiable);

    void addGameCard(QString gameImagePath, QString gamePlayHours, QString gameName, QString lastTimePlayed);

    void addFriendCrad(QString profileImagePath, QString profileName, QString lastSeen);


private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
