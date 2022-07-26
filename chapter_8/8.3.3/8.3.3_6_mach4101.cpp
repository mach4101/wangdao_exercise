//
// Created by mach4101 on 2022/7/26.
// 荷兰国旗问题 => 本质是快排的一次划分

#include<iostream>
using namespace std;

void Partition(int Color[], int length) {
    int i = 0, j = 0, k = length - 1; // i前面是红色，k后面是蓝色，j是扫描的工作指针
    while(j <= k) {
        if(Color[j] == 0) {  // 如果扫描到红色，和第一个元素交换
            swap(Color[i], Color[j]);
            i ++;
            j ++;
        } else if(Color[j] == 1) { // 如果是白色，什么也不做
            j ++;
        } else { // 如果是蓝色
            swap(Color[j], Color[k]);
            k --;
            // 这个地方不用j --，因为可能之前的Color[k]也是蓝色，如果j+1那么这个蓝色就会被跳过
        }
    }
}

int main() {
    //假设红为0，白为1，蓝为2
    int Color[10] = { 1,0,1,2,2,1,2,0,1,2 };
    cout << "原数组为：";
    for(int i = 0; i < 10; ++i) {
        cout << Color[i] << " ";
    }
    cout << endl;

    Partition(Color, 10);

    cout << "调整后的数组为：";
    for(int i = 0; i < 10; ++i) {
        cout << Color[i] << " ";
    }
    cout << endl;
    return 0;
}

