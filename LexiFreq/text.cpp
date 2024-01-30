#include "text.h"
#include "ui_text.h"
#include "binarytree.h"
#include "hashtableadd.h"
#include "hashtablechanied.h"
#include "linearlist.h"
#include "linkedlist.h"
#include "text.h"
#include <QMessageBox>
#include <QDebug>

Text::Text(Menu* MENU,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Text)
{
    ui->setupUi(this);
    QByteArray title="统计检索系统";
    setWindowTitle(QString::fromLocal8Bit(title));
    this->MENU=MENU;
}

Text::~Text()
{
    delete ui;
}

void Text::on_SaveButton_clicked()
{
    QString Qword=ui->lineEdit->text();
    string word=Qword.toStdString();
    int freq;
    double time,length;
    if(1==MENU->structType){
        if(1==MENU->searchType){
            LinearList LL;
            Build(LL);
            Search_S(LL,word,freq,time,length);
        }
        else{
            LinearList LL;
            Build(LL);
            Search_B(LL,word,freq,time,length);
        }

    }
    else if(2==MENU->structType){
        LinkedList LL;
        Build(LL);
        Search(LL,word,freq,time,length);
        Free(LL);

    }
    else if(3==MENU->structType){
        BinaryTree BT;
        Build(BT);
        Search(BT,word,freq,time,length);
        Free(BT);
    }
    else if(4==MENU->structType){
        HashTable_Add HT;
        Build(HT);
        Search(HT,word,freq,time,length);
    }
    else if(5==MENU->structType){
        HashTable_Chained HT;
        Build(HT);
        Search(HT,word,freq,time,length);
        Free(HT);
    }
    qDebug()<<QString::fromStdString(word)<<" "<<freq<<" "<<time<<" "<<length;

    QByteArray message;
    if(freq>0){
    message="单词:"+Qword.toUtf8()
            +"<br>词频："+QString::number(freq).toUtf8()
            +"<br>查找时间:"+QString::number(time,'f',2).toUtf8()
            +" ns<br>平均查找长度"+QString::number(length,'f',2).toUtf8();
    }
    else{
        message="查找失败。";
    }
    QMessageBox::information(this,QString::fromLocal8Bit("查找结果"),QString::fromLocal8Bit(message));

}
