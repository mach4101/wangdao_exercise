//
// Created by mach4101 on 2022/7/25.
// 改编快排，枢纽结点从列表中随机选取

#include <iostream>
using namespace std;

int Partition(int a[], int low, int high) {
    int pivot = a[rand() % (high - low + 1) + low];  // 随机从数组中选择一个元素作为枢纽
    while(low < high) {
        while(low < high && a[high] >= pivot) --high;  // 从右往左，找到第一个比枢纽小的
        a[low] = a[high];

        while(low < high && a[low] <= pivot) ++ low;   // 从左往右，找到第一个比枢纽大的
        a[high] = a[low];
    }

    a[low] = pivot;                                    // 枢纽还原
    return low;                                        // 返回位置

}

void QuickSort(int a[], int low, int high) {
    if(low < high) {
        int pivotpos = Partition(a, low, high);
        QuickSort(a, low, pivotpos - 1);
        QuickSort(a, pivotpos + 1, high);
    }
}

int main() {
    int a[11] = {2,5,21,54,64,12,65,34,12,37,21};
    cout << "原数组为：";
    for(int i = 0; i < 11; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    QuickSort(a, 0, 10);

    cout << "排序后的数组为：";
    for(int i = 0 ; i < 11; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

