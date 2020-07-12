#include "friendcard.h"

FriendCard::FriendCard(QWidget *parent) : QWidget(parent)
{

}

FriendCard::FriendCard(QWidget *parent, QString profileImagePath, QString profileName, QString lastSeen) : QWidget(parent)
{
    styleLabelName(profileName);
    styleLabelLastOnline(lastSeen);
    styleLabelProfileImg(profileImagePath);
    QVBoxLayout *vLayout = new QVBoxLayout();
    QHBoxLayout *hLayout = new QHBoxLayout();
    vLayout->addWidget(this->labelName);
    vLayout->addWidget(this->labelLastOnline);
    vLayout->setAlignment(Qt::AlignLeft);
    hLayout->addWidget(labelProfileImg);
    hLayout->addLayout(vLayout);
    this->setLayout(hLayout);
    this->setFixedSize(250, 53);
}

void FriendCard::styleLabelProfileImg(QString path)
{
    QPixmap p(path);
    this->labelProfileImg->setPixmap(p);
    this->labelProfileImg->setScaledContents(true);
    this->labelProfileImg->setFixedSize(QSize(50, 50));
}

void FriendCard::styleLabelName(QString name)
{
    this->labelName->setText(name);
    this->setStyleSheet("QLabel{color:gray;background-color:transparent;margin-right:80px}");
}

void FriendCard::styleLabelLastOnline(QString lastSeen)
{
    this->labelLastOnline->setText(lastSeen);
    this->setStyleSheet("QLabel{color:gray;background-color:transparent}");
}
