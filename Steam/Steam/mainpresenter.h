#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QDialog>
#include <QPixmap>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainPresenter; }
QT_END_NAMESPACE

class MainPresenter : public QDialog
{
    Q_OBJECT

public:
    MainPresenter(QWidget *parent = nullptr);
    ~MainPresenter();

private slots:
    void on_btnStore_clicked();

    void on_btnLibrary_clicked();

    void on_btnCommunity_clicked();

    void on_btnProfile_clicked();

private:
    Ui::MainPresenter *ui;
    void initialize();
};
#endif // MAINPRESENTER_H
