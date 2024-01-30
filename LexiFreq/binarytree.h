#ifndef BINARYTREE_H
#define BINARYTREE_H
#include"Menu.h"
using namespace std;

//¶þ²æÅÅÐòÊ÷
extern int nodeNum;
struct BTNode{
    string data;
    struct BTNode* lChild;
    struct BTNode* rChlld;
    int freq;
};
struct BinaryTree{
    struct BTNode* root;

};
void Insert(BinaryTree &L,string word);
void Build(BinaryTree &L);
void Search(BinaryTree L,string word,int& freq,double& time,double& length);
void Count(BinaryTree &L);
void Traversal(BTNode* node);
void Free(BinaryTree &L);
void FreeNode(BTNode* node);
#endif // BINARYTREE_H
