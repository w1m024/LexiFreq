#include "widget.h"
#include "ui_widget.h"
#include"menu1.h"
#include"menu2.h"
#include"menu4.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QByteArray title="统计检索系统";
    setWindowTitle(QString::fromLocal8Bit(title));
    Menu* MENU=new Menu;
    MENU->searchType=1;
    MENU->structType=1;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_LLButton_clicked()//转到menu2
{
    this->close();
    Menu1* menu1=new Menu1(MENU);
    menu1->show();
}

void Widget::on_BTButton_clicked()
{
    MENU->structType=3;
    this->close();
    Menu4* menu4=new Menu4(MENU);
    menu4->show();
}

void Widget::on_HTButton_clicked()
{
    this->close();
    Menu2* menu2=new Menu2(MENU);
    menu2->show();
}

void Widget::on_ExitButton_clicked()
{
    this->close();
}
