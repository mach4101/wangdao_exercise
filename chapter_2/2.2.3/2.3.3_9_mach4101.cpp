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

void process(SqList & sqList, int x) {
    int index;

    for(int i = 0; i < sqList.length; ++i) {
        if(sqList.a[i] == x) { //若找到
            swap(sqList.a[i], sqList.a[i + 1]);
            return;
        }

        if(sqList.a[i] > x) { //已经比x大了，说明没有找到
            //从尾部开始往右挪动一个单元，留出位置插入x
            for(int j = sqList.length - 1; j >= i; --j) {
                sqList.a[j + 1] = sqList.a[j];
            }
            sqList.a[i] = x;
            sqList.length ++;
            return;
        }
    }
}

void print(SqList sqList){
    for (int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;
}

int main() {
    SqList sqList;

    cout << "处理前的数组为：";
    print(sqList);

    process(sqList, 7);

    cout << "处理后的数组为：";
    print(sqList);

    process(sqList, 6);

    cout << "处理后的数组为：";
    print(sqList);
    return 0;
}