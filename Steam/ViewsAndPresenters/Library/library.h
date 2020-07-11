#ifndef LIBRARY_H
#define LIBRARY_H

#include "Library_global.h"
#include <QWidget>
#include <QQmlContext>

#include "../../Steam/copyablewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Library; }
QT_END_NAMESPACE

class LIBRARY_EXPORT Library : public CopyableWidget
{
    Q_OBJECT
public:
    Library(QWidget *parent = nullptr);
    ~Library();

    CopyableWidget * copy() override;

private:
    Ui::Library *ui;
};


#endif // LIBRARY_H
