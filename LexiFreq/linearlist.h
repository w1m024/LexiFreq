#ifndef LINEARLIST_H
#define LINEARLIST_H
#include<chrono>
#include"Menu.h"
using namespace std;
const int MAXSIZE=5010;
//���Ա�
struct LinearList{
    string data[MAXSIZE];
    int length=0;
};
void Insert(LinearList &L,string word);
void Build(LinearList &L);
void Search_S(LinearList L,string word,int& freq,double& time,double& length);//˳�����
void Search_B(LinearList L,string word,int& freq,double& time,double& length);//�۰����
void Sort(LinearList &L);//���򣬸���ʵ���۰�����
void QuickSort(LinearList &L,int left,int right);//���ţ�����ʵ���۰�����
void Count(LinearList L);


#endif // LINEARLIST_H
