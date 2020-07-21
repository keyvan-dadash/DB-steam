#include "resultcard.h"

ResultCard::ResultCard(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *qVboxLayout = new QVBoxLayout();
    QHBoxLayout *qHboxLayout = new QHBoxLayout();

    qlabelTitle->setStyleSheet("QLabel{ color:white; background:transparent; font-size:20px;}");
    qlabelExtraAttribute->setStyleSheet("QLabel{ color: #2f89bc; background:transparent; font-size:16px; }");
    qVboxLayout->addWidget(qlabelTitle);
    qVboxLayout->addWidget(qlabelExtraAttribute);
    qlabelImg->setFixedSize(QSize(60, 60));
    qHboxLayout->addWidget(qlabelImg);
    qHboxLayout->addLayout(qVboxLayout);
    this->setLayout(qHboxLayout);
    this->setFixedSize(QSize(1000,80));
}

void ResultCard::setTitle(QString title)
{
    this->qlabelTitle->setText(title);
}

void ResultCard::setExtraAttribute(QString extra)
{
    this->qlabelExtraAttribute->setText(extra);
}

void ResultCard::setImg(QString path)
{
    QPixmap img(path);
    this->qlabelImg->setPixmap(img);
    this->qlabelImg->setScaledContents(true);
}

QString ResultCard::getHubName()
{
    return hubName;
}

void ResultCard::setHubName(QString hubName)
{
    this->hubName = hubName;
}
