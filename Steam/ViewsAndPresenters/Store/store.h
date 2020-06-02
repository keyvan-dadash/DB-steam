#ifndef STORE_H
#define STORE_H

#include "Store_global.h"
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Store; }
QT_END_NAMESPACE


class STORE_EXPORT Store : public QWidget
{
    Q_OBJECT
public:
    Store(QWidget *parent = nullptr);
    ~Store();

private:
    Ui::Store *ui;
};

#endif // STORE_H
