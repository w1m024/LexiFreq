#include"LinearList.h"
#include <QDebug>
#define filePath "C:/InFile.txt"

int nodeNum1=0;
void Build(LinearList &L){
    ifstream file(filePath);
    string word;
    while(file>>word){
        nodeNum1++;
        for(int i=0;i<word.length();++i){
            if(ispunct(word[i])){
                word.erase(i--,1);
            }
            else if (isalpha(word[i])) {
                word[i]=tolower(word[i]);
            }
        }
        Insert(L,word);
    }
    file.close();
}

void Insert(LinearList &L, string word){
    L.data[++L.length]=word;
}

void Search_S(LinearList L, string word, int &freq, double &time, double &length){
    qDebug()<<"startt="<<std::chrono::high_resolution_clock::now().time_since_epoch().count();
    auto startt=chrono::high_resolution_clock::now();
    freq=0;
    int idx=1;
    while(idx<=L.length){
        if(L.data[idx]==word){
            freq++;
        }
        idx++;
    }
    length=L.length;
    if(freq==0) return;
    qDebug()<<"res="<<L.length<<" /"<<freq;
    auto endt=chrono::high_resolution_clock::now();
    qDebug()<<"endt="<<std::chrono::high_resolution_clock::now().time_since_epoch().count();
    time = chrono::duration_cast<chrono::nanoseconds>(endt - startt).count();
    //cout<<startt.time_since_epoch().count()<<'\n';//
    //cout<<endt.time_since_epoch().count()<<'\n';//
}

void Search_B(LinearList L, string word, int &freq, double &time, double &length){
    //Sort(L);
    QuickSort(L,1,L.length);
    auto startt=chrono::high_resolution_clock::now();
    length = 0;
    int l = 0, r = -1;//word◊Û”“±ﬂΩÁ
    int left = 1, right = L.length;
    while (left <= right) {//’“◊Û±ﬂΩÁ
        length++;
        int mid = left + (right - left) / 2;
        if (L.data[mid]< word) {
            left = mid + 1;
        }
        else if (L.data[mid]>word) {
            right = mid - 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (left < L.length + 1 && L.data[left] == word) {//≈–◊Û±ﬂΩÁ¥Ê‘⁄
        l = left;
        right = L.length;
        while (left <= right) {//’“”“±ﬂΩÁ
            length++;
            int mid = left + (right - left) / 2;
            if (L.data[mid]< word) {
                left = mid + 1;
            }
            else if (L.data[mid]> word) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (right >= 0 && L.data[right] == word)//≈–”“±ﬂΩÁ¥Ê‘⁄
            r = right;
    }
    else {
        l = 0;
    }
    freq = r - l + 1;
    if(freq==0) return;
    auto endt=chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(endt - startt).count();
}

void Sort(LinearList &L){//√∞≈›≈≈–Ú
    for(int i=1;i<=L.length;++i){
        for(int j=1;j<L.length-i+1;++j){
            if(L.data[j]>L.data[j+1]){
                swap(L.data[j],L.data[j+1]);
            }
        }
    }
}

void QuickSort(LinearList &L,int left,int right){//øÏÀŸ≈≈–Ú
    int l=left,r=right;
    string pivot=L.data[(left+right)/2];
    while(l<=r){
        while(L.data[l]<pivot)
            l++;
        while(L.data[r]>pivot)
            r--;
        if(l<=r){
            swap(L.data[l],L.data[r]);
            l++;
            r--;
        }
    }
    if(left<r){
        QuickSort(L,left,r);
    }
    if(l<right){
        QuickSort(L,l,right);
    }
}

void Count(LinearList L){
    //Sort(L);
    QuickSort(L,1,L.length);
    ofstream outfile("output.txt");
    for(int i=1;i<=L.length;++i){
        int freq=1;
        while(L.data[i+1]==L.data[i]&&i<=L.length){
            freq++;
            i++;
        }
        if(freq*100>=nodeNum1){
            qDebug()<<"outfile";
            outfile<<L.data[i]<<" "<<freq<<'\n';
        }
    }
    outfile.close();
}
