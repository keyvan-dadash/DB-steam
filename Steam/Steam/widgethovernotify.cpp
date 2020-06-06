#include "widgethovernotify.h"

WidgetHoverNotify::WidgetHoverNotify(QWidget *parent) : QWidget(parent)
{

}

bool WidgetHoverNotify::event(QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        emit enterHover();
    } else if (event->type() == QEvent::Leave) {
        emit exitHover();
    }
    return QWidget::event(event);
}
