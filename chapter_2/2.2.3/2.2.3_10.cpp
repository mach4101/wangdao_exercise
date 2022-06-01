/* **************************************************
 * Filename: 2.2.3_10.cpp
 *   Create: 2022-05-28
 *   Author: Wulnut
 * *************************************************/

#include <iostream>
using namespace std;

typedef int ElemType;

void reverse(ElemType arr[], int begin, int end) {
    int i = begin;
    int j = end;
    int temp;

    while (i < j) {
        temp = arr[i];
        arr[i ++] = arr[j]; // 先把arr[j]放入arr[i], i在往后移动
        arr[j --] = temp;
    }
}

void converse(ElemType arr[], int length, int round) {
    int m = round % length;
    reverse(arr, 0, m - 1);
    reverse(arr, m, length - 1);
    reverse(arr, 0, length - 1);

    for (int i =0; i < length; ++ i) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    converse(arr, 6, 2);
    return 0;
}
