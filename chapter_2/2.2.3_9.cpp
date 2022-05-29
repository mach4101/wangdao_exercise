/* **************************************************
 * Filename: 2.2.3_9.cpp
 *   Create: 2022-05-26
 *   Author: Wulnut
 * *************************************************/
#include <iostream>
using namespace std;

typedef int ElemType;

void SearchExchangeInsert(ElemType A[], ElemType x, int n) {

    // 二分查找
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] == x) break;
        else if(A[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    // 查找到数据，并且坐标不在最后一位
    if (A[mid] == x && mid != n - 1) {
        int t = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = t;
    }

    // 如果查找失败，插入元素x
    if (low > high) {
        int i;
        for (i = n - 1; i > high; -- i) A[i + 1] = A[i]; // 插入数据之后会把最后一位数据丢弃，可以提前设置一个MAXSIZE
        A[i + 1] = x;
    }
}

int main() {
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    SearchExchangeInsert(A, 0, 10);

    for (int m : A) {
        printf("%d ", m);
    }

    return 0;
}