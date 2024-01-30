#ifndef LINEARLIST_H
#define LINEARLIST_H
#include<chrono>
#include"Menu.h"
using namespace std;
const int MAXSIZE=5010;
//œﬂ–‘±Ì
struct LinearList{
    string data[MAXSIZE];
    int length=0;
};
void Insert(LinearList &L,string word);
void Build(LinearList &L);
void Search_S(LinearList L,string word,int& freq,double& time,double& length);//À≥–Ú≤È’“
void Search_B(LinearList L,string word,int& freq,double& time,double& length);//’€∞Î≤È’“
void Sort(LinearList &L);//≈≈–Ú£¨∏®÷˙ µœ÷’€∞Î≈≈–Ú
void QuickSort(LinearList &L,int left,int right);//øÏ≈≈£¨∏®÷˙ µœ÷’€∞Î≈≈–Ú
void Count(LinearList L);


#endif // LINEARLIST_H
