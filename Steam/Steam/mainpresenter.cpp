#include "mainpresenter.h"
#include "ui_mainview.h"
#include "store.h"
#include "profile.h"

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
    for(QObject *child : ui->frameWidget->children()) {
        delete child;
    }
    Store *store = new Store(ui->frameWidget);
    store->setFixedSize(ui->frameWidget->size());
    ui->frameWidget->stackUnder(store);
    ui->frameWidget->setStyleSheet(store->styleSheet());
    store->show();
}

void MainPresenter::on_btnLibrary_clicked()
{

}

void MainPresenter::on_btnCommunity_clicked()
{

}

void MainPresenter::on_btnProfile_clicked()
{
    for(QObject *child : ui->frameWidget->children()) {
        delete child;
    }
    Profile *profile = new Profile(ui->frameWidget);
    profile->setFixedSize(ui->frameWidget->size());
    ui->frameWidget->stackUnder(profile);
    ui->frameWidget->setStyleSheet(profile->styleSheet());
    profile->show();
}

void MainPresenter::widgetEnterHover()
{
    detemineBehaviorOfWidget(qobject_cast<QWidget*>(sender()), true);
}

void MainPresenter::widgetExitHover()
{
    detemineBehaviorOfWidget(qobject_cast<QWidget*>(sender()), false);
}

void MainPresenter::initialize()
{
    ui->labelLogoImg->setPixmap(QPixmap("D:\\fucking uni\\DB\\project\\globalheader_logo.png"));

    //create drop button for each button
    makeStoreDropDownButtons();
    makeLibraryDropDownButtons();
    makeCommunityDropDownButtons();
    makeProfileDropDownButtons();

    //hide listwidgets
    detemineBehaviorOfWidget(ui->widgetStore, false);
    detemineBehaviorOfWidget(ui->widgetLibrary, false);
    detemineBehaviorOfWidget(ui->widgetCommunity, false);
    detemineBehaviorOfWidget(ui->widgetProfile, false);

    //make connection notify when hovered on widget and then shod listwidgets
    makeConnectionForHoverWidget(ui->widgetStore);
    makeConnectionForHoverWidget(ui->widgetLibrary);
    makeConnectionForHoverWidget(ui->widgetCommunity);
    makeConnectionForHoverWidget(ui->widgetProfile);
}

void MainPresenter::addButtonToListWidget(QListWidget *listWidget, QString buttonText)
{
    QListWidgetItem *list = new QListWidgetItem(listWidget);
    list->setSizeHint(QSize(listWidget->width(), 25));
    list->setBackground(QColor(0, 0, 0));
    listWidget->addItem(list);
    QPushButton *btn = new QPushButton();
    btn->setText(buttonText);
    btn->setStyleSheet("QPushButton"
    "{"
        "color:#b8b6b4;"
        "background:#171a21;"
        "text-align:left;"
        "padding-left:5px;"
    "}"
    "QPushButton:hover"
    "{"
        "color:#fff;"
    "}");
    btn->setFlat(true);
    listWidget->setItemWidget(list, btn);

    int height = 0;
    for(int i = 0; i < listWidget->count(); ++i)
    {
        QListWidgetItem* item = listWidget->item(i);
        height += item->sizeHint().height();
    }
    listWidget->setFixedHeight(height);
}

void MainPresenter::makeStoreDropDownButtons()
{
    for(QString text : storeSubButtonTexts) {
        addButtonToListWidget(ui->listWidgetStore, text);
    }
}

void MainPresenter::makeLibraryDropDownButtons()
{
    for(QString text : librarySubButtonTexts) {
        addButtonToListWidget(ui->listWidgetLibrary, text);
    }
}

void MainPresenter::makeCommunityDropDownButtons()
{
    for(QString text : communitySubButtonTexts) {
        addButtonToListWidget(ui->listWidgetCommunity, text);
    }
}

void MainPresenter::makeProfileDropDownButtons()
{
    for(QString text : profileSubButtonTexts) {
        addButtonToListWidget(ui->listWidgetProfile, text);
    }
}

void MainPresenter::detemineBehaviorOfWidget(QWidget *widget, bool status)
{
    if(!status) {
        widget->setFixedHeight(51); //sry i have no choice but to hardcode this
    } else {
        int height = 0;
        for(QObject *child : widget->children())
        {
            height += qobject_cast<QWidget*>(child)->height();
        }
        widget->setFixedHeight(height);
    }
}

void MainPresenter::makeConnectionForHoverWidget(QWidget *widget)
{
    connect(widget, SIGNAL(enterHover()), this, SLOT(widgetEnterHover()));
    connect(widget, SIGNAL(exitHover()), this, SLOT(widgetExitHover()));
}
