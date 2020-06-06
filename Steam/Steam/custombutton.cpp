#include "custombutton.h"

CustomButton::CustomButton(QWidget *parent) : QPushButton(parent)
{

}


bool CustomButton::event(QEvent *e)
{
    if(e->type() == QEvent::HoverEnter){
        emit enterHover();
    } else if(e->type() == QEvent::HoverLeave) {
        emit exitHover();
    }
    return QPushButton::event(e);
}
