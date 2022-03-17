//
// Created by mach4101 on 2022/3/17.
//从有序表中删除s到t之间的元素s<t且包含s和t

#include <iostream>
using namespace std;
#define MAX 100

typedef struct SqList{
    int a[MAX] = {1, 2, 3, 3,3, 5, 6, 7, 7, 7, 8, 8,9 ,9, 10, 11};
    int length = 16;
} SqList;

void process(SqList & sqList) {
    int count = 0;
    for(int i = 1; i < sqList.length; ++i) {
        if(sqList.a[i] == sqList.a[i - 1 - count]) { //当前元素和前count + 1个元素相同
            count++;
        } else {
            sqList.a[i - count] = sqList.a[i];
        }
    }
    sqList.length -= count;
}

int main() {
    SqList sqList;

    cout << "原数组元素为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;

    process(sqList);

    cout << "处理后的数组为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;
    return 0;
}