#include "friends.h"
#include "ui_friends.h"

Friends::Friends(QWidget *parent):
    CopyableWidget(parent), ui(new Ui::Friends)
{
    ui->setupUi(this);
    ui->quickWidgetFriends->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
}

Friends::~Friends()
{
    delete ui;
}

CopyableWidget *Friends::copy()
{
    return new Friends();
}
