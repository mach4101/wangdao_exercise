//
// Created by mach4101 on 2022/3/17.
//从有序表中删除s到t之间的元素s<t且包含s和t

#include <iostream>
using namespace std;
#define MAX 100

typedef struct SqList{
    int a[MAX] = {1, 2, 3, 4, 5, 6, 7, 7, 7, 8, 8, 9, 10, 11};
    int length = 14;
} SqList;

void process(SqList & sqList, int s, int t) {
    int count  = 0;
    for(int i = 0; i < sqList.length; ++i) {
        if(sqList.a[i] > s && sqList.a[i] < t) {
            count ++;
        } else {
            sqList.a[i - count] = sqList.a[i];
        }
    }
    sqList.length -= count;
}

int main() {
    SqList sqList;
    int s = 3, t = 5;
    if(s >= t || sqList.length == 0) {
        cout << "error" << endl;
        return 0;
    }
    cout << "原数组元素为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;

    process(sqList, s, t);

    cout << "处理后的数组为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;
    return 0;
}