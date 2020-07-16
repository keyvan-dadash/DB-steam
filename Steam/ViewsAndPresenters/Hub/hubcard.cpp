#include "hubcard.h"

HubCard::HubCard(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *qVboxLayout = new QVBoxLayout();
    QHBoxLayout *qHboxLayout = new QHBoxLayout();

    qlabelName->setStyleSheet("QLabel{ color:white; background:transparent; font-size:14px;}");
    qlabelTopicsCount->setStyleSheet("QLabel{ color: #2f89bc; background:transparent; font-size:12px; }");
    qVboxLayout->addWidget(qlabelName);
    qVboxLayout->addWidget(qlabelTopicsCount);
    qlabelHubImg->setStyleSheet("QLabel{ background:red; }");
    qlabelHubImg->setFixedSize(QSize(30, 30));
    qHboxLayout->addWidget(qlabelHubImg);
    qHboxLayout->addLayout(qVboxLayout);
    this->setLayout(qHboxLayout);
    this->setFixedSize(QSize(345,52));
}

void HubCard::setHubName(QString hubName)
{
    this->qlabelName->setText(hubName);
}

void HubCard::setNumberOfRecentDiscussion(QString discussionCount)
{
    this->qlabelTopicsCount->setText(discussionCount);
}

void HubCard::setHubImage(QString path)
{
    QPixmap img(path);
    this->qlabelHubImg->setPixmap(img);
    this->qlabelHubImg->setScaledContents(true);
}

QString HubCard::getHubName()
{
    return this->qlabelName->text();
}
