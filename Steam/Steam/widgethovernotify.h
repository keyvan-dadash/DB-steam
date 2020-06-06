#ifndef WIDGETHOVERNOTIFY_H
#define WIDGETHOVERNOTIFY_H

#include <QWidget>
#include <QEvent>
#include <QDebug>

class WidgetHoverNotify : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetHoverNotify(QWidget *parent = nullptr);

protected:
    bool event(QEvent *event) override;

signals:

    void enterHover();

    void exitHover();

};

#endif // WIDGETHOVERNOTIFY_H
