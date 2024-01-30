#include "menu3.h"
#include "ui_menu3.h"
#include "menu1.h"
#include "menu4.h"
Menu3::Menu3(Menu* MENU,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu3)
{
    ui->setupUi(this);
    QByteArray title="统计检索系统";
    setWindowTitle(QString::fromLocal8Bit(title));
    this->MENU=MENU;
}

Menu3::~Menu3()
{
    delete ui;
}

void Menu3::on_LinearButton_clicked()
{
    MENU->structType=1;
    this->close();
    Menu4* menu4=new Menu4(MENU);
    menu4->show();
}

void Menu3::on_LinkedButton_clicked()
{
    MENU->structType=2;
    this->close();
    Menu4* menu4=new Menu4(MENU);
    menu4->show();
}

void Menu3::on_BackButton3_clicked()
{
    this->close();
    Menu1* menu1=new Menu1(MENU);
    menu1->show();
}
