//
// Created by mach4101 on 2022/7/25.
// 将奇数结点移动到偶数结点的前面

#include<iostream>
using namespace std;

// 采用双指针的思想，flag初始指向列表中的第一个元素，i从前往后扫描，当扫描到奇数元素时，和flag进行交换，然后flag++，直到数组遍历完
void MoveOdds(int a[], int length) {
    int flag = 0; //
    for(int i = 0; i < length; ++i) {
        if(a[i] % 2 == 1) {
            swap(a[i], a[flag]);
            flag ++;
        }
    }
}

int main() {
    int a[11] = {2,5,21,54,64,12,65,34,12,37,21};
    cout << "原数组为：";
    for(int i = 0; i < 11; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    MoveOdds(a, 11);

    cout << "移动后的数组为：";
    for(int i = 0 ; i < 11; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

