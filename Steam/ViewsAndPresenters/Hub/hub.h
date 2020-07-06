#ifndef HUB_H
#define HUB_H

#include "Hub_global.h"
#include "../../Steam/copyablewidget.h"
#include <QWidget>
#include <QQmlContext>

QT_BEGIN_NAMESPACE
namespace Ui { class Hub; }
QT_END_NAMESPACE

class HUB_EXPORT Hub : public CopyableWidget
{
    Q_OBJECT
public:
    Hub(QWidget *parent = nullptr);
    ~Hub();

    CopyableWidget * copy() override;

private:
    Ui::Hub *ui;
};

#endif // HUB_H
