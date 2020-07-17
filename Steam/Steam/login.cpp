#include "login.h"
#include "ui_login.h"

Login::Login(DataBase *database, QWidget *parent)
    : QDialog(parent), database(database)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    btnLoginDisableStyle();
}

Login::~Login()
{
    delete ui;
}


void Login::on_lineEditPassword_textChanged(const QString &arg1)
{
    if(arg1.length() == 0)
    {
        btnLoginDisableStyle();
        return;
    }
    btnLoginEnableStyle();
}

void Login::btnLoginEnableStyle()
{
    ui->btnLogin->setEnabled(true);
    ui->btnLogin->setStyleSheet("QPushButton { \
                                min-width: 190px; \
                                background-color:	#888888; \
                                color: white; } \
                                QPushButton:hover{ \
                                color: palette(dark); }");
}

void Login::btnLoginDisableStyle()
{
    ui->btnLogin->setEnabled(false);
    ui->btnLogin->setStyleSheet("QPushButton {opacity: 0.1;}");
}

void Login::on_btnCancel_clicked()
{
    reject();
}

void Login::on_btnLogin_clicked()
{
    QString username = ui->lineEditAccountName->text();
    QString password = ui->lineEditPassword->text();
    if(this->database->getUserQuery()->userLogin(username, password)){
        emit loginStatus(true);
        this->accept();
    }
    else {
        //create acc and wrong pass login here
    }
}

void Login::on_btnCreate_clicked()
{

}
