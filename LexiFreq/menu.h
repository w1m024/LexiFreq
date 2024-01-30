#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<fstream>
#include<string>
#include<chrono>

using namespace std;
class Menu{
public:
    int structType;//线性表1、链表2、二叉排序树3，开放地址法哈希表4，链地址法哈希表5
    int searchType;//顺序查找1，折半查找2
};
#endif // MENU_H
