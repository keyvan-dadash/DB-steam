#include "mainpresenter.h"
#include "ui_mainview.h"

MainPresenter::MainPresenter(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainPresenter)
{
    ui->setupUi(this);
    initialize();
}

MainPresenter::~MainPresenter()
{
    delete ui;
}


void MainPresenter::on_btnStore_clicked()
{

}

void MainPresenter::on_btnLibrary_clicked()
{

}

void MainPresenter::on_btnCommunity_clicked()
{

}

void MainPresenter::on_btnProfile_clicked()
{

}

void MainPresenter::initialize()
{
    ui->labelLogoImg->setPixmap(QPixmap("D:\\fucking uni\\DB\\project\\globalheader_logo.png"));
}
