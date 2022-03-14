//
// Created by mach4101 on 2022/3/13.
//
// 1. 删除最小值的元素
// 2. 返回最小值
// 3. 最小值的地方用最后一个元素填补
#include<iostream>
using namespace std;

#define MaxSize 100

typedef struct SqList {
    int a[MaxSize] = {1, 1, 4, 5, 1, 4, 0, 9, 1, 9, 8, 1, 10};
    int length = 13;

} SqList;

int main() {
    SqList sqList;
    cout << "原数组为：";
    if(sqList.length == 0) {
        cout << "error, the array is empty";
        return 0;
    }
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;

    int minx = sqList.a[0], index = 0;
    for(int i = 0; i < sqList.length; ++i) {
        if(sqList.a[i] < minx) {
            index = i;
            minx = sqList.a[i];
        }

    }

    sqList.a[index] = sqList.a[sqList.length - 1];
    sqList.length -= 1;

    cout << "现在的元素为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;
    return 0;
}