#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QDialog>
#include <QPixmap>
#include <QDebug>
#include <QListWidget>

#include "widgethovernotify.h"
#include "copyablewidget.h"

//library
#include "store.h"
#include "profile.h"
#include "friends.h"
#include "hub.h"
#include "library.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainPresenter; }
QT_END_NAMESPACE

class MainPresenter : public QDialog
{
    Q_OBJECT

public:
    MainPresenter(DataBase *database, QWidget *parent = nullptr);

    ~MainPresenter();

    struct ButtonAndPresenterPair
    {
        QString buttonText;
        CopyableWidget *presenter;

        ButtonAndPresenterPair(QString buttonText, CopyableWidget *presenter):buttonText(buttonText), presenter(presenter) {};
    };

    QList<ButtonAndPresenterPair> storeSubButtonTexts = {
        ButtonAndPresenterPair{"Featured", nullptr},
        ButtonAndPresenterPair{"News", nullptr},
        ButtonAndPresenterPair{"Top Games", nullptr},
        ButtonAndPresenterPair{"Top Sales", nullptr}
    };

    QList<ButtonAndPresenterPair> librarySubButtonTexts = {
        ButtonAndPresenterPair{"Home", new Library(database)},
        ButtonAndPresenterPair{"Collections", nullptr}
    };

    QList<ButtonAndPresenterPair> communitySubButtonTexts = {
        ButtonAndPresenterPair{"Home", nullptr},
        ButtonAndPresenterPair{"Discussions", nullptr},
        ButtonAndPresenterPair{"Workshop", nullptr}
    };

    QList<ButtonAndPresenterPair> profileSubButtonTexts = {
        ButtonAndPresenterPair{"Profile", new Profile(database)},
        ButtonAndPresenterPair{"Friends", new Friends(database)},
        ButtonAndPresenterPair{"Inventory", nullptr}
    };

    QString dropDownButtonStyleSheet = "QPushButton"
                                       "{"
                                           "color:#b8b6b4;"
                                           "background:#171a21;"
                                           "text-align:left;"
                                           "padding-left:5px;"
                                       "}"
                                       "QPushButton:hover"
                                       "{"
                                           "color:#fff;"
                                       "}";


private slots:
    void on_btnStore_clicked();

    void on_btnLibrary_clicked();

    void on_btnCommunity_clicked();

    void on_btnProfile_clicked();

    void widgetEnterHover();

    void widgetExitHover();

    void on_listWidgetStore_currentRowChanged(int currentRow);

private:
    Ui::MainPresenter *ui;

    DataBase *database;

    void initialize();

    void changePresenter(QWidget *widget); //set presenter widget

    void addButtonToListWidget(QListWidget *listWidget, ButtonAndPresenterPair &btnPresenter);

    void makeStoreDropDownButtons();

    void makeLibraryDropDownButtons();

    void makeCommunityDropDownButtons();

    void makeProfileDropDownButtons();

    void detemineBehaviorOfWidget(QWidget *widget, bool status);

    void makeConnectionForHoverWidget(QWidget *widget);
};
#endif // MAINPRESENTER_H
