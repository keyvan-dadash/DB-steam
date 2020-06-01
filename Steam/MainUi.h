#ifndef MAINUI_H
#define MAINUI_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainUi; }
QT_END_NAMESPACE

class MainUi : public QDialog
{
    Q_OBJECT

public:
    MainUi(QWidget *parent = nullptr);
    ~MainUi();

private:
    Ui::MainUi *ui;
};
#endif // MAINUI_H
