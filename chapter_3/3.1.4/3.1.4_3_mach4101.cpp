//
// Created by mach4101 on 2022/6/17.
//

#include<iostream>
using namespace std;

bool check(char A[]) {
    int count = 0;      // 用一个变量来判断
    for(int i = 0; i < 8; i ++) { // 扫描数组
        if(A[i] == 'I')           // 如果是I就加，是O就减
            count++;
        else
            count--;
        if(count < 0) return false; //如果在某次操作中出现出栈过多，就返回false
    }
    return true;  //如果至始至终都没出现false，那么返回true；
}

int main() {
    char a[8] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
    char b[8] = {'I', 'O', 'O', 'I', 'O', 'I', 'I', 'O'};
    char c[8] = {'I', 'I', 'I', 'O', 'I', 'O', 'I', 'O'};
    char d[8] = {'I', 'I', 'I', 'O', 'O', 'I', 'O', 'O'};

    if(check(a)) {  // 改这个地方测试序列是否满足要求
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}