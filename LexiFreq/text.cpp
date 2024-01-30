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
    QByteArray title="ͳ�Ƽ���ϵͳ";
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
    message="����:"+Qword.toUtf8()
            +"<br>��Ƶ��"+QString::number(freq).toUtf8()
            +"<br>����ʱ��:"+QString::number(time,'f',2).toUtf8()
            +" ns<br>ƽ�����ҳ���"+QString::number(length,'f',2).toUtf8();
    }
    else{
        message="����ʧ�ܡ�";
    }
    QMessageBox::information(this,QString::fromLocal8Bit("���ҽ��"),QString::fromLocal8Bit(message));

}
