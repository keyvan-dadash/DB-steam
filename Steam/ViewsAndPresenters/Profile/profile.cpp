#include "profile.h"
#include "ui_profile.h"


Profile::Profile(QWidget *parent) :
    CopyableWidget(parent), ui(new Ui::Profile)
{
    ui->setupUi(this);
}

Profile::~Profile()
{
    delete ui;
}

CopyableWidget *Profile::copy()
{
    return new Profile();
}
