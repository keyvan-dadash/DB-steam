#include "library.h"
#include "ui_library.h"

Library::Library(QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Library)
{
    ui->setupUi(this);
    ui->quickWidgetLibrary->setSource(QUrl(QStringLiteral("qrc:/libraryMain.qml")));
    this->obj = ui->quickWidgetLibrary->rootObject();

    this->setUpLibrary(QList<QString>{"tom", "ac", "fifa"},
                       QList<QString>{"256", "38", "2"},
                       QList<QList<QString>>{
                           QList<QString>{"file:///D:\\fucking uni\\DB\\project\\exxx1.jpg", "file:///D:\\fucking uni\\DB\\project\\exxx2.jpg"},
                           QList<QString>{"file:///D:\\fucking uni\\DB\\project\\ex1.jpg", "file:///D:\\fucking uni\\DB\\project\\ex2.jpg"}
                       }
                       );
}

Library::~Library()
{
    delete ui;
}

CopyableWidget *Library::copy()
{
    return new Library();
}

void Library::setUpLibrary(QList<QString> gamesList, QList<QString> totalGamePlayList, QList<QList<QString> > imagesList)
{
    this->obj->setProperty("gamesList", this->toVariantList(gamesList));
    this->obj->setProperty("totalGamePlayList", this->toVariantList(totalGamePlayList));
    QVariantList wholeList;
    foreach(QList<QString> list, imagesList) {
        wholeList.push_back(this->toVariantList(list));
    }
    this->obj->setProperty("imagesList", wholeList);
}

template<typename T>
QVariantList Library::toVariantList( const QList<T> &list )
{
    QVariantList newList;
    foreach( const T &item, list )
        newList << item;

    return newList;
}
