#include "menu2.h"
#include "ui_menu2.h"
#include "widget.h"
#include "menu4.h"

Menu2::Menu2(Menu* MENU,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu2)
{
    ui->setupUi(this);
    QByteArray title="统计检索系统";
    setWindowTitle(QString::fromLocal8Bit(title));
    this->MENU=MENU;
}

Menu2::~Menu2()
{
    delete ui;
}

void Menu2::on_AddButton_clicked()
{
    MENU->structType=4;
    this->close();
    Menu4* menu4=new Menu4(MENU);
    menu4->show();
}

void Menu2::on_ChaButton_clicked()
{
    MENU->structType=5;
    this->close();
    Menu4* menu4=new Menu4(MENU);
    menu4->show();
}

void Menu2::on_BackButton2_clicked()
{
    this->close();
    Widget* widget=new Widget;
    widget->show();
}
