//
// Created by mach4101 on 2022/3/16.
//
/**
 * 删除线性表中所有值为x的元素
 *
 * */
#include<iostream>
using namespace std;

#define MAX 100

typedef struct SqList {
    int a[MAX] = {1, 2, 4, 5, 6, 7, 7, 6, 5, 4, 2, 7};
    int length = 12;
};

void process(SqList & sqList, int x) {
    //往后面扫描的同时记录x的数量
    int count = 0;
    for(int i = 0; i < sqList.length; ++i) {
        if(sqList.a[i] == x) count++;
        else
            sqList.a[i - count] = sqList.a[i];
    }
    sqList.length -= count;
}

int main() {
    SqList sqList;
    cout << "原数组为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;

    process(sqList, 6);

    cout << "删除x后的数组为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;
    return 0;
}