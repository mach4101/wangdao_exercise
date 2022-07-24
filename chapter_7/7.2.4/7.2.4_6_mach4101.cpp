//
// Created by mach4101 on 2022/7/24.
//

// 找到一个结点的时候，将这个结点与其前驱结点交换

#include<iostream>
using namespace std;

int a[11] = {0, 1, 5, 9, 11, 15, 17, 19, 20, 21, 25};

int SwitchSearch(int a[], int key) {
    for(int i = 0; i < 11; ++i) {
        if(a[i] == key) {
            if(i != 0) { // 只要不是第一个元素，就将这个元素和前面的结点交换
                int t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                return i - 1;
            }
            return i;

        }
    }
}

int main() {
    int key = 9;
    cout << "数组下标在：" << SwitchSearch(a, key) << endl;

    for(int i = 0; i < 11; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

