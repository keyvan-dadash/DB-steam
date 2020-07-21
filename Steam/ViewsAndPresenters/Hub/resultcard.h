#ifndef RESULTCARD_H
#define RESULTCARD_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRandomGenerator>
#include <QDebug>

class ResultCard : public QWidget
{
    Q_OBJECT
public:
    explicit ResultCard(QWidget *parent = nullptr);

    void setTitle(QString title);

    void setExtraAttribute(QString extra);

    void setImg(QString path);

    QString getHubName();

    void setHubName(QString hubName);

signals:

private:
    QLabel *qlabelTitle = new QLabel();

    QLabel *qlabelExtraAttribute = new QLabel();

    QLabel *qlabelImg = new QLabel();

    QString hubName;
};

#endif // RESULTCARD_H
