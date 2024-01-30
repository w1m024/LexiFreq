#include"BinaryTree.h"
#include<stack>
#include <QDebug>
#define filePath "C:/InFile.txt"

int nodeNum=0;
void Build(BinaryTree &L){
    ifstream file(filePath);
    string word;
    while(file>>word){
        nodeNum++;
        for(int i=0;i<word.length();++i){
            if(ispunct(word[i])){
                word.erase(i--,1);
            }
            else if (isalpha(word[i])) {
                word[i]=tolower(word[i]);
            }
        }
        if(nodeNum==1){
            L.root=new BTNode;
            L.root->data=word;
            L.root->freq=1;
            L.root->lChild=nullptr;
            L.root->rChlld=nullptr;
        }
        else
            Insert(L,word);
    }
    file.close();
}

void Insert(BinaryTree &L, string word){
    BTNode* cur=L.root;
    BTNode* newNode=new BTNode;
    newNode->data=word;
    newNode->lChild=nullptr;
    newNode->rChlld=nullptr;
    newNode->freq=1;
    while(true){
        if(word<cur->data){
            if(cur->lChild==nullptr){
                cur->lChild=newNode;
                return;
            }
            cur=cur->lChild;
        }else if(word>cur->data){
            if(cur->rChlld==nullptr){
                cur->rChlld=newNode;
                return;
            }
            cur=cur->rChlld;
        }else{
            cur->freq++;
            delete newNode;
            return;
        }
    }
}

void Search(BinaryTree L, string word, int &freq, double &time, double &length){
    auto startt=chrono::high_resolution_clock::now();
    freq=0,length=1;
    BTNode* cur=L.root;
    while(cur){
        length++;
        if(word<cur->data){
            cur=cur->lChild;
        }else if(word>cur->data){
            cur=cur->rChlld;
        }else{
            freq=cur->freq;
            break;
        }
    }
    if(cur==nullptr) return;
    auto endt=chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(endt - startt).count();
}

void Count(BinaryTree &L){
    Traversal(L.root);
}
void Traversal(BTNode* node){

    if(node){
        ofstream outfile("output.txt");
        if(outfile.is_open()){
        stack<BTNode*>stack;
        stack.push(node);

        while(!stack.empty()){
            BTNode* cur=stack.top();
            stack.pop();
            if(cur->freq*100>=nodeNum)
                outfile<<cur->data<<" "<<cur->freq<<'\n';
            if(cur->lChild){
                stack.push(cur->lChild);
            }
            if(cur->rChlld){
                stack.push(cur->rChlld);
            }
        }
        outfile.close();
        }
        else{
            qDebug()<<"文件打开失败";
        }
    }
}
void Free(BinaryTree &L){
    FreeNode(L.root);
}

void FreeNode(BTNode* node){
    if(node){
        FreeNode(node->lChild);
        FreeNode(node->rChlld);
        delete node;
    }
}
