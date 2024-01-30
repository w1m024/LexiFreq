#include"HashTableAdd.h"
#define filePath "C:/InFile.txt"

int nodeNum4=0;
int getHash(string word){
    int num=0;
    for(int i=0;i<word.length();++i){
        num*=10;
        num+=word[i];
        num%=MOD;
    }
    return num;
}

void Build(HashTable_Add &L){
    for(int i=0;i<MOD;++i){
        L.data[i]="";
        L.flags[i]=0;
    }

    ifstream file(filePath);
    string word;
    while(file>>word){
        nodeNum4++;
        for(int i=0;i<word.length();++i){
            if(ispunct(word[i])){
                word.erase(i--,1);
            }
            else if (isalpha(word[i])) {
                word[i]=tolower(word[i]);
            }
        }

        int num=getHash(word);
        int idx=num,i=1;
        if(L.flags[idx]==0){
            L.data[idx]=word;
            L.flags[idx]=1;
        }else{
            if(L.data[idx]==word){
                L.flags[idx]++;
            }
            else{

                while(L.flags[idx]!=0&&L.data[idx]!=word){
                    idx=(num+i*i)%MOD;
                    i++;
                }
                if(L.flags[idx]==0){
                    L.data[idx]=word;
                    L.flags[idx]=1;}
                else{
                    L.flags[idx]++;
                }
            }
        }
    }
    file.close();
}

void Search(HashTable_Add L, string word, int &freq, double &time, double &length){
    auto startt=chrono::high_resolution_clock::now();
    length=1;
    int num=getHash(word);
    int idx=num,i=1;
    while(L.flags[idx]>0&&L.data[idx]!=word){
        idx=(num+i*i)%MOD;
        i++;
        length++;
    }
    if(L.flags[idx]==0){
        freq=0;
    }else{
        freq=L.flags[idx];
    }
    if(freq==0) return;
    auto endt=chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(endt - startt).count();
}

void Count(HashTable_Add L){
    ofstream outfile("output.txt");
    for(int i=0;i<MOD;++i){
        if(L.flags[i]>0){
            if(L.flags[i]*100>=nodeNum4){
                outfile<<L.data[i]<<" "<<L.flags[i]<<'\n';
            }
        }
    }
}
