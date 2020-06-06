#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>


class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CustomButton(QWidget *parent = nullptr);

protected:
    bool event(QEvent *e) override;

signals:
    void enterHover();
    void exitHover();
};

#endif // CUSTOMBUTTON_H
