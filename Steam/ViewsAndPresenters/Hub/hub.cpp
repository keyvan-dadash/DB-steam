#include "hub.h"
#include "ui_hub.h"

Hub::Hub(QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Hub)
{
    ui->setupUi(this);
    ui->quickWidgetHub->setSource(QUrl(QStringLiteral("qrc:/hubMain.qml")));
}

Hub::~Hub()
{
    delete ui;
}

CopyableWidget *Hub::copy()
{
    return new Hub();
}
