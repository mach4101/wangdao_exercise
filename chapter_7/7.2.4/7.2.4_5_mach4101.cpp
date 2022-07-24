//
// Created by mach4101 on 2022/7/24.
// 折半查找递归版
#include<iostream>
using namespace std;

// 假设最开始数组长度为10，元素如下
int a[11] = {0, 1, 5, 9, 11, 15, 17, 19, 20, 21, 25};

// 返回所在位置，如果没有则返回-1
int BinarySearch(int a[], int key, int low, int high) {
    int mid = (low + high) / 2;
    if(low <= high) {
        if(a[mid] == key)
            return mid;
        else if(a[mid] > key) { // 左半边寻找
            return BinarySearch(a, key, low, mid - 1);
        } else{                 // 右半边寻找
            return BinarySearch(a, key, mid + 1, high);
        }
    } else {
        return -1;
    }
}

int main() {
    cout << BinarySearch(a, 10, 1, 11); // 在a中查找11， low为1， high为表长
    return 0;
}