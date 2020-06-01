#include "MainUi.h"
#include "ui_MainUi.h"

MainUi::MainUi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainUi)
{
    ui->setupUi(this);
}

MainUi::~MainUi()
{
    delete ui;
}

