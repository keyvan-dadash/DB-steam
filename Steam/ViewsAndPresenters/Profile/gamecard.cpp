#include "gamecard.h"

GameCard::GameCard(QWidget *parent) : QWidget(parent)
{

}

GameCard::GameCard(QWidget *parent, QString gameImagePath, QString gamePlayHours, QString gameName, QString lastTimePlayed) : QWidget(parent)
{
    styleLabelHours(gamePlayHours);
    styleLabelLastPlayed(lastTimePlayed);
    styleBtnGame(gameName);
    styleLabelGameImg(gameImagePath);
    widgetStyle();
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(this->labelHours);
    vLayout->addWidget(this->labelLastPlayed);
    vLayout->setAlignment(Qt::AlignRight);
    hLayout->addWidget(this->labelGameImg);
    hLayout->addWidget(this->btnGame);
    hLayout->addLayout(vLayout);
    this->setLayout(hLayout);
    this->setFixedSize(680 ,103);
}

void GameCard::styleBtnGame(QString gameName)
{
    this->btnGame->setFlat(true);
    this->btnGame->setText(gameName);
    this->btnGame->setStyleSheet("QPushButton{"
                                 "padding-bottom:60px;"
                                 "text-align:left;"
                                 "color:white;"
                                 "font-size:15px"
                                 "}"
                                 "QPushButton:hover{"
                                 "color: #66c0f4;"
                                 "}");
    QFontMetrics fm(this->btnGame->font());
    this->setFixedSize(fm.horizontalAdvance(gameName), fm.height());
}

void GameCard::styleLabelHours(QString gamePlayHours)
{
    this->labelHours->setText(gamePlayHours);
    this->labelHours->setStyleSheet("QLabel{color:gray;background-color:transparent;margin-top:50px}");
}

void GameCard::styleLabelLastPlayed(QString lastTimePlayed)
{
    this->labelLastPlayed->setText(lastTimePlayed);
    this->labelLastPlayed->setStyleSheet("QLabel{color:gray;background-color:transparent}");
}

void GameCard::styleLabelGameImg(QString path)
{
    QPixmap p(path);
    this->labelGameImg->setPixmap(p);
    this->labelGameImg->setScaledContents(true);
    this->labelGameImg->setFixedSize(QSize(230, 100));
}

void GameCard::widgetStyle()
{
    this->setStyleSheet("");
}
