/* **************************************************
 * Filename: 2.2.3_8.cpp
 *   Create: 2022-05-25
 *   Author: Wulnut
 * *************************************************/

#include<iostream>
using namespace std;

#define MaxSize 100

//已知在一维数组A[m+n]中依次存放两个线性表（a1-am）,（b1-bm）。将数组中两个顺序表位置互换

//三次逆置，整体逆置，两次内部逆置
void reverse(int A[], int left, int right, int arraySize) {
    if(left >= right || right >= arraySize) return;

    int mid = (left + right) / 2;
    for(int i = 0; i <= mid - left; i ++) {//上限错了
        int tmp = A[left + i]; // 首部放入寄存器
        A[left + i] = A[right - i]; // 尾部放入首部
        A[right - i] = tmp; // 首部数据放入尾部
    }
}

//控制三次逆置
void Exchange(int A[], int m, int n, int arraySize) {
    reverse(A,0,m + n - 1, arraySize);
    reverse(A,0,n - 1, arraySize);
    reverse(A,n,m + n - 1, arraySize);
}

int main() {
    int m, n;//分别代表两个线性表A,B的长度
    int A[MaxSize];
    cout << "请输入线性表A和线性表B的长度:";
    cin >> m >> n;

    cout << "请输入线性表A的值：";
    for (int i=0;i<m;i++) cin >> A[i];

    cout << "请输入线性表B的值：";

    for(int i=m;i<m+n;i++) cin >> A[i];
    cout << "数组为：" << endl;

    for(int i=0;i<m+n;i++) cout<<A[i]<<" ";

    cout<<endl;

    Exchange(A, m, n, MaxSize);

    cout << "互换后的数组为：" << endl;
    for(int i = 0; i < m + n; i++)
        cout<<A[i]<<" ";

    cout<<endl;
    return 0;
}