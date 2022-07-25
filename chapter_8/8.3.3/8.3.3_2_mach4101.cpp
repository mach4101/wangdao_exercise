//
// Created by mach4101 on 2022/7/25.
// 双向冒泡排序算法

#include<iostream>
using namespace std;

void DeSort(int a[], int length) {
    int low = 0, high = length;

    while(low < high) {
        int flag = 1;
        for(int i = low; i < high - 1; i++) {  // 从前往后，把大的放最后
            if(a[i] > a[i + 1]) {
                flag = 0;                      // 如果有交换，那么说明序列还不是有序状态
                swap(a[i], a[i + 1]);
            }
        }

        high --;          // 最大值已经就位，设置high往前挪动

        if(flag == 1) break; // 如果flag = 1说明，在上一次排序的过程中并没有涉及到交换 => 已经有序

        for(int i = high; i > low; i--) {   // 从后往前，把小的放最前
            if(a[i - 1] > a[i]) {
                swap(a[i], a[i - 1]);
            }
        }
        low ++;          // 最小值已经就位，设置low往后挪动


    }
}

int main() {
    int a[11] = {2,5,21,54,64,12,65,34,12,37,21};
    cout << "原序列：";
    for(int i = 0; i < 11; ++i)
        cout << a[i] << " ";
    cout << endl;

    DeSort(a,11);

    cout << "排序后：";
    for(int i = 0; i < 11; ++i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}


