//
// Created by mach4101 on 2022/6/3.
//

#include <iostream>
using namespace std;
#define MAX 100

typedef struct SqList{
    int a[MAX] = {1, 2, 3, 4, 5, 6, 10, 11, 12};
    int length = 9;
} SqList;

void swap(int & a, int & b) {
    int t = a;
    a = b;
    b = t;
}

void reverse(SqList & sqList, int start, int end) {  //逆置start到end这一段区间的顺序表
    int mid = (end + start) / 2;
    for (int i = start; i < mid; ++i) {
        swap(sqList.a[i], sqList.a[end - i + start]);
    }
}

//将sqList中的前m个元素与后n个元素互换位置, start和end表示要逆置的顺序表的下标区间
void process(SqList & sqList, int m, int n) {
    //先将整个表逆置，然后将前n个元素逆置，再将后m个元素逆置
    reverse(sqList, 0, sqList.length - 1);
    reverse(sqList, 0, n - 1);
    reverse(sqList, n, m + n - 1);
}

void print(SqList sqlist){
    for (int i = 0; i < sqlist.length; ++i) {
        cout << sqlist.a[i] << " ";
    }
    cout << endl;
}

int main() {
    SqList sqList;

    cout << "处理前的数组为：";
    print(sqList);

    process(sqList, 6, 3);

    cout << "处理后的数组为：";
    print(sqList);
    return 0;
}