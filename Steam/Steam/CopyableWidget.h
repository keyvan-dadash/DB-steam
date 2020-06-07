#ifndef COPYABLEWIDGET_H
#define COPYABLEWIDGET_H

#include <QWidget>

class CopyableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CopyableWidget(QWidget *parent = nullptr);

    virtual CopyableWidget *copy() = 0; //this return new of own class make share when you implement this you set parent after
                                        //get object and also you can implement copy logic
signals:

};

#endif // COPYABLEWIDGET_H
