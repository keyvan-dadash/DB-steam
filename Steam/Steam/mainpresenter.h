#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QDialog>
#include <QPixmap>
#include <QDebug>
#include <QListWidget>

#include "custombutton.h"
#include "customlistwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainPresenter; }
QT_END_NAMESPACE

class MainPresenter : public QDialog
{
    Q_OBJECT

public:
    MainPresenter(QWidget *parent = nullptr);

    ~MainPresenter();

    QStringList storeSubButtonTexts = {"Featured", "News", "Top Games", "Top Sales"};

    QStringList librarySubButtonTexts = {"Home", "Collections"};

    QStringList communitySubButtonTexts = {"Home", "Discussions", "Workshop"};

    QStringList profileSubButtonTexts = {"Profile", "Friends", "Inventory"};

private slots:
    void on_btnStore_clicked();

    void on_btnLibrary_clicked();

    void on_btnCommunity_clicked();

    void on_btnProfile_clicked();

    void widgetEnterHover();

    void widgetExitHover();

private:
    Ui::MainPresenter *ui;

    void initialize();

    void addButtonToListWidget(QListWidget *listWidget, QString buttonText);

    void makeStoreDropDownButtons();

    void makeLibraryDropDownButtons();

    void makeCommunityDropDownButtons();

    void makeProfileDropDownButtons();

    void detemineBehaviorOfWidget(QWidget *widget, bool status);

    void makeConnectionForHoverWidget(QWidget *widget);
};
#endif // MAINPRESENTER_H
