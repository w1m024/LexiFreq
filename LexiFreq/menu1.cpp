#include "menu1.h"
#include "ui_menu1.h"
#include "widget.h"
#include "menu3.h"
#include "menu4.h"

Menu1::Menu1(Menu* MENU,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu1)
{
    ui->setupUi(this);
    QByteArray title="统计检索系统";
    setWindowTitle(QString::fromLocal8Bit(title));
    this->MENU=MENU;
}

Menu1::~Menu1()
{
    delete ui;
}

void Menu1::on_SSearchButton_clicked()
{
    MENU->searchType=1;
    this->close();
    Menu3* menu3=new Menu3(MENU);
    menu3->show();
}

void Menu1::on_BSearchButton_clicked()
{
    MENU->structType=1;
    MENU->searchType=2;
    this->close();
    Menu4* menu4=new Menu4(MENU);
    menu4->show();
}

void Menu1::on_BackButton1_clicked()
{
    this->close();
    Widget* widget=new Widget;
    widget->show();
}
