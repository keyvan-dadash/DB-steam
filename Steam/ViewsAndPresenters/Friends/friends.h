#ifndef FRIENDS_H
#define FRIENDS_H

#include "Friends_global.h"
#include <QWidget>
#include <QQmlContext>

#include "../../Steam/copyablewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Friends; }
QT_END_NAMESPACE

class FRIENDS_EXPORT Friends : public CopyableWidget
{
    Q_OBJECT
public:
    Friends(QWidget *parent = nullptr);
    ~Friends();

    CopyableWidget * copy() override;

private:
    Ui::Friends *ui;
};

#endif // FRIENDS_H
