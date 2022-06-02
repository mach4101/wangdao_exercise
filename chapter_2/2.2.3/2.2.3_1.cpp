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


// 处理过程
void process(SqList & sqList) {
    int minx = sqList.a[0], index = 0;            // 首先假设数组中的第一个元素是最小的元素，index用于记录最小值所在的数组下标
    for(int i = 0; i < sqList.length; ++i) {      // 遍历顺序表
        if(sqList.a[i] < minx) {                  // 如果有元素比最小的元素还要小
            index = i;                            // 把这个元素的位置记录
            minx = sqList.a[i];                   // 并且更新当前元素为最小值元素
        }
    }

    sqList.a[index] = sqList.a[sqList.length - 1]; // 将空出的位置由最后一个元素填补
    sqList.length -= 1;                            // 顺序表的长度减一
}

int main() {
    SqList sqList;
    if(sqList.length == 0) {
        cout << "error, the array is empty";
        return 0;
    }

    cout << "原数组为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;

    process(sqList);

    cout << "现在的元素为：";
    for(int i = 0; i < sqList.length; ++i) {
        cout << sqList.a[i] << " ";
    }
    cout << endl;
    return 0;
}