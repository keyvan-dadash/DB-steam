#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QDebug>

#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(DataBase *database, QWidget *parent = nullptr);
    ~Login();

signals:
    void loginStatus(bool status);

private slots:
    void on_lineEditPassword_textChanged(const QString &arg1);

    void on_btnCancel_clicked();

    void on_btnLogin_clicked();

    void on_btnCreate_clicked();

    void on_backPushButton_clicked();

    void on_createAccPushButton_clicked();

private:
    Ui::Login *ui;

    DataBase *database;

    void btnLoginEnableStyle();

    void btnLoginDisableStyle();

    void checkBoxHoverStyle(QCheckBox *checkbox);

    bool validateEmail(QString email);

};
#endif // LOGIN_H
