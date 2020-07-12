#ifndef LIBRARY_H
#define LIBRARY_H

#include "Library_global.h"
#include <QWidget>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include <QList>
#include <QDebug>
#include <QQmlEngine>

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

    template <typename T>
    QVariantList toVariantList(const QList<T> &list);

    void setUpLibrary(QList<QString> gamesList, QList<QString> totalGamePlayList, QList<QList<QString>> imagesList);

private:
    Ui::Library *ui;
    QObject *obj; //rootobject of qtquickview
};


#endif // LIBRARY_H
