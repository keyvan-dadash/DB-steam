#include "mainpresenter.h"
#include "ui_mainview.h"


MainPresenter::MainPresenter(DataBase *database, QWidget *parent)
    : QDialog(parent), database(database)
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
    changePresenter(new Store(database));
}

void MainPresenter::on_btnLibrary_clicked()
{
    changePresenter(new Library(database));
}

void MainPresenter::on_btnCommunity_clicked()
{
    changePresenter(new Hub(database));
}

void MainPresenter::on_btnProfile_clicked()
{
    changePresenter(new Profile(database));
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

void MainPresenter::changePresenter(QWidget *widget)
{
    for(QObject *child : ui->frameWidget->children()) {
        delete child;
    }
    widget->setParent(ui->frameWidget);
    widget->setFixedSize(ui->frameWidget->size());
    ui->frameWidget->stackUnder(widget);
    ui->frameWidget->setStyleSheet(widget->styleSheet());
    widget->show();
}

void MainPresenter::addButtonToListWidget(QListWidget *listWidget, ButtonAndPresenterPair &btnPresenter)
{
    QListWidgetItem *list = new QListWidgetItem(listWidget);
    list->setSizeHint(QSize(listWidget->width(), 25));
    list->setBackground(QColor(0, 0, 0));
    listWidget->addItem(list);
    QPushButton *btn = new QPushButton();
    btn->setText(btnPresenter.buttonText);
    btn->setStyleSheet(dropDownButtonStyleSheet);
    btn->setFlat(true);
    listWidget->setItemWidget(list, btn);
    btn->connect(btn, &QPushButton::clicked, this, [=](){
        if(btnPresenter.presenter != nullptr) {
            qInfo() << btnPresenter.presenter;
            this->changePresenter(btnPresenter.presenter->copy());
        }
    });
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
    for(ButtonAndPresenterPair item : storeSubButtonTexts) {
        addButtonToListWidget(ui->listWidgetStore, item);
    }
}

void MainPresenter::makeLibraryDropDownButtons()
{
    for(ButtonAndPresenterPair item : librarySubButtonTexts) {
        addButtonToListWidget(ui->listWidgetLibrary, item);
    }
}

void MainPresenter::makeCommunityDropDownButtons()
{
    for(ButtonAndPresenterPair item : communitySubButtonTexts) {
        addButtonToListWidget(ui->listWidgetCommunity, item);
    }
}

void MainPresenter::makeProfileDropDownButtons()
{
    for(ButtonAndPresenterPair item : profileSubButtonTexts) {
        addButtonToListWidget(ui->listWidgetProfile, item);
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
