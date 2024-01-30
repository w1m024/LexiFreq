#include"LinkedList.h"

#include<unordered_map>

#define filePath "C:/InFile.txt"

int nodeNum2=0;
void Build(LinkedList &L){
    int idx=0;
    L.head=new LLNode;
    L.head->next=nullptr;
    LLNode* cur=L.head;
    ifstream file(filePath);
    string word;
    while(file>>word){
        nodeNum2++;
        for(int i=0;i<word.length();++i){
            if(ispunct(word[i])){
                word.erase(i--,1);
            }
            else if (isalpha(word[i])) {
                word[i]=tolower(word[i]);
            }
        }

        LLNode* newNode=new LLNode;
        newNode->data=word;
        newNode->next=nullptr;
        //cout<<++idx<<" "<<newNode->data<<'\n';
        cur->next=newNode;
        cur=cur->next;
    }
    file.close();
}

void Search(LinkedList &L, string word, int &freq, double &time, double &length){
    auto startt=chrono::high_resolution_clock::now();
    freq=0;
    LLNode* cur=L.head;
    while(cur){
        if(cur->data==word){
            freq++;
        }
        cur=cur->next;
    }
    if(freq==0) return;
    length=nodeNum2;
    auto endt=chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(endt - startt).count();
}

void Count(LinkedList &L){
    unordered_map<string,int>map;
    LLNode*cur=L.head;
    while(cur){
        map[cur->data]++;
        cur=cur->next;
    }
    ofstream outfile("output.txt");
    for(auto&pair:map){
        if(pair.first==""){
            continue;
        }
        if(pair.second*100>=nodeNum2)
            outfile<<pair.first<<" "<<pair.second<<'\n';
    }
}

void Free(LinkedList &L){
    LLNode* cur=L.head;
    while(cur){
        LLNode* temp=cur;
        cur=cur->next;
        delete temp;
    }
    L.head=nullptr;
}

