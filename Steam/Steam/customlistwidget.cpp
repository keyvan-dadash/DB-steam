#include "customlistwidget.h"

CustomListWidget::CustomListWidget(QWidget *parent) : QListWidget(parent)
{

}

bool CustomListWidget::event(QEvent *e)
{
    if (e->type() == QEvent::Enter) {
        emit enterHover();
    } else if (e->type() == QEvent::Leave) {
        emit exitHover();
    }
    return QListWidget::event(e);
}
