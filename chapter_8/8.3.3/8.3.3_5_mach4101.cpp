//
// Created by mach4101 on 2022/7/25.
#include<iostream>
using namespace std;
int Kth(int a[], int low, int high, int k) {
    if (low == high) return a[low];
    int mid = a[low];

    int ldx = low - 1, rdx = high + 1;  //执行的是do while
    while(ldx < rdx) { // 快排交换元素模板
        do ldx ++; while (a[ldx] < mid);
        do rdx --; while(a[rdx] > mid);

        if(ldx < rdx) swap(a[ldx], a[rdx]);
    }

    int leftLength = rdx - low + 1;  // 区间左边的长度
    if(k <= leftLength) return Kth(a, low, rdx, k);  // 如果第k小数在左半区间，那么在左半区间中找第k小的元素
    return Kth(a, rdx + 1, high, k - leftLength);  // 如果第k小的数在右半区间，那么在右半区间中找第 k - leftLength小的元素
}

int main() {
    int a[11] = {2,5,21,54,64,12,65,34,12,37,21};
    cout << "原数组为：";
    for(int i = 0; i < 11; ++i)
        cout << a[i] << " ";
    cout << endl;
    cout << Kth(a, 0, 10, 3); // 找到第3小的数
    return 0;
}

