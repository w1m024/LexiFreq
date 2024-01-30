#ifndef HASHTABLECHANIED_H
#define HASHTABLECHANIED_H

#include"Menu.h"

#define MOD 10000
using namespace std;
//Á´µØÖ··¨¹þÏ£±í
struct HTNode{
    string data;
    struct HTNode* next;
    int freq;
};

struct HashTable_Chained{
    struct HTNode* array[MOD];
};
int getHash(string word);
void Build(HashTable_Chained &L);
void Search(HashTable_Chained L,string word,int& freq,double& time,double& length);
void Count(HashTable_Chained L);
void Free(HashTable_Chained &L);
void FreeNode(HTNode* node);
#endif // HASHTABLECHANIED_H
