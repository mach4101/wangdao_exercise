//
// Created by mach4101 on 2022/3/13.
//

#include <iostream>
using  namespace std;
#define MaxSize 100
typedef struct SqList{
    int length = 13;
    int a[MaxSize] = {1, 1, 4, 5, 1, 4, 0, 9, 1, 9, 8, 1, 10};
} SqList;

void swap(int & a, int & b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    SqList sqList;
    int mid = sqList.length / 2;
    cout << "原数组为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < mid; ++i){
        swap(sqList.a[i], sqList.a[sqList.length - i - 1]);
    }

    cout << "逆置后的数组为：";
    for (int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;
}