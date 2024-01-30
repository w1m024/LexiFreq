
#ifndef HASHTABLEADD_H
#define HASHTABLEADD_H
#include"Menu.h"

#define MOD 10000

using namespace std;

struct HashTable_Add{
    string data[MOD];
    int flags[MOD];
};
int getHash(string word);
void Build(HashTable_Add &L);
void Search(HashTable_Add L,string word,int& freq,double& time,double& length);
void Count(HashTable_Add L);
#endif // HASHTABLEADD_H

