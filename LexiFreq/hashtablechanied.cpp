#include"HashTableChanied.h"
#define filePath "C:/InFile.txt"

int nodeNum5=0;
void Build(HashTable_Chained &L){
    ///int idx=0;
    ifstream file(filePath);
    string word;
    while(file>>word){
        nodeNum5++;
        for(int i=0;i<word.length();++i){
            if(ispunct(word[i])){
                word.erase(i--,1);
            }
            else if (isalpha(word[i])) {
                word[i]=tolower(word[i]);
            }
        }
        HTNode* newNode=new HTNode;
        newNode->data=word;
        newNode->next=nullptr;
        newNode->freq=1;

        int num=getHash(word);

        HTNode* cur=L.array[num];
        HTNode*prev=nullptr;
        while(cur){

            if(cur->data==word){
                cur->freq++;
                break;
            }
            prev=cur;
            cur=cur->next;
        }

        if(!cur){

            if(prev){
                prev->next=newNode;
            }else{

                L.array[num]=newNode;
            }
        }
    }
    file.close();
}

void Search(HashTable_Chained L, string word, int &freq, double &time, double &length){
    auto startt=chrono::high_resolution_clock::now();
    freq=0,length=1;
    int num=getHash(word);
    HTNode* cur=L.array[num];
    while(cur&&cur->next&&cur->data!=word){
        cur=cur->next;
    }

    if(cur){
        freq=cur->freq;
    }else{
        freq=0;
        return;
    }

    auto endt=chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(endt - startt).count();
}

void Count(HashTable_Chained L){

    ofstream outfile("output.txt");
    for(int i=0;i<MOD;++i){
        HTNode* cur=L.array[i];
        while(cur){
            if(cur->freq*100>=nodeNum5){
                outfile<<cur->data<<" "<<cur->freq<<'\n';
            }
            cur=cur->next;
        }
    }
}
void Free(HashTable_Chained &L){
    for(int i=0;i<MOD;++i)
        FreeNode(L.array[i]);
}
void FreeNode(HTNode* node){
    while(node){
        HTNode* temp=node;
        node=node->next;
        delete temp;
    }
}

