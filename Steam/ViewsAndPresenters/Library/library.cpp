#include "library.h"
#include "ui_library.h"

Library::Library(QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Library)
{
    ui->setupUi(this);
    ui->quickWidgetLibrary->setSource(QUrl(QStringLiteral("qrc:/libraryMain.qml")));
}

Library::~Library()
{
    delete ui;
}

CopyableWidget *Library::copy()
{
    return new Library();
}
