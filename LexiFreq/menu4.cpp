#include "menu4.h"
#include "ui_menu4.h"
#include "widget.h"
#include "binarytree.h"
#include "hashtableadd.h"
#include "hashtablechanied.h"
#include "linearlist.h"
#include "linkedlist.h"
#include "text.h"
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <windows.h>
#include <QString>

Menu4::Menu4(Menu* MENU,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu4)
{
    ui->setupUi(this);
    QByteArray title="统计检索系统";
    setWindowTitle(QString::fromLocal8Bit(title));
    this->MENU=MENU;
}

Menu4::~Menu4()
{
    delete ui;
}

void Menu4::on_CountBuutton_clicked()
{
    qDebug()<<MENU->structType;//
    if(1==MENU->structType){
        LinearList LL;
        Build(LL);
        Count(LL);
    }
    else if(2==MENU->structType){
        LinkedList LL;
        Build(LL);
        Count(LL);
        Free(LL);

    }
    else if(3==MENU->structType){
        BinaryTree BT;
        Build(BT);
        Count(BT);
        Free(BT);

    }
    else if(4==MENU->structType){
        HashTable_Add HT;
        Build(HT);
        Count(HT);
    }
    else if(5==MENU->structType){
        HashTable_Chained HT;
        Build(HT);
        Count(HT);
        Free(HT);
    }
    QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("词频统计结果已保存为output.txt"));
    QProcess* pro=new QProcess(this);
    char path[200];
    GetModuleFileNameA(NULL,path,200);
    int signNum=0;
    int pathLength=sizeof(path)/sizeof(path[0]);
    for(int i=pathLength-1;i>=0;--i){

        if(path[i]=='\\')
            signNum++;
        if(signNum==2){
            qDebug()<<"Changepath";
            path[i+1]='\0';
            break;
        }
    }

    QString savePath="notepad "+QString::fromLocal8Bit(path)+"output.txt";
    qDebug()<<savePath;
    pro->start(savePath);
}

void Menu4::on_SearchButton_clicked()
{
    qDebug()<<MENU->structType;//

    Text* text=new Text(MENU);
    text->show();
}

void Menu4::on_BackButton4_clicked()
{
    this->close();
}
