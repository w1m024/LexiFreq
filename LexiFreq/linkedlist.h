#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include"Menu.h"
using namespace std;
//Á´±í
struct LLNode{
    string data;
    LLNode* next;
};
struct LinkedList{
    struct LLNode* head;
};
void Build(LinkedList &L);
void Search(LinkedList &L,string word,int& freq,double& time,double& length);
void Count(LinkedList &L);
void Free(LinkedList &L);
#endif // LINKEDLIST_H
