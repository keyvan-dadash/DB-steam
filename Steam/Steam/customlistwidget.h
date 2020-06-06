#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QEvent>
#include <QDebug>

class CustomListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit CustomListWidget(QWidget *parent = nullptr);

protected:
    bool event(QEvent *e) override;

signals:
    void enterHover();
    void exitHover();

};

#endif // CUSTOMLISTWIDGET_H
