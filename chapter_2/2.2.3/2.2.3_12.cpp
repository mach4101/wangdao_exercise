/* **************************************************
 * Filename: 2.2.3_12.cpp
 *   Create: 2022-05-28
 *   Author: Wulnut
 * *************************************************/

#include <iostream>
using namespace std;

// 摩尔投票法
int MooreVoting(int arr[],int n){

    int x,count;
    x=0;
    count=0;    //表示一个虚拟数组
    for (int i=0; i<n; i++) {

        if (count==0) {
            //虚拟数组为空，加入当前元素
            x=arr[i];
            count = 1;
        }
        else if (x==arr[i]){

            count++;   //数组非空，当前元素与虚拟数组元素相同，加入当前元素
        }
        else{

            count--;   //数组非空，当前元素与虚拟数组元素不同，删除一对不相同的元素
        }
    }
    return x;
}

// 暴力查找计数法
int MajorNum(int arr[],int n){

    //i如果在循环内n定义运行出错 未解决
    int c,count,i;
    c = arr[0];
    count = 1;
    for ( i = 1; i < n; i ++) {

        if (arr[i] == c) {
            //对A中的候选主元素计数
            count ++;
        }
        else {

            if (count == 0) {
                //更换主元素  重新计数
                c=arr[i];
                count =1;
            }
            else                //处理不是候选主元素
                count--;
        }

    }
    for (i = 0,count = 0; i < n; i ++) {
        //实际出现的次数
        if (arr[i] == c) {

            count ++;
        }
    }
    if (count > n / 2) {

        return c;
    }
    else
        return -1;
}

int main() {
     int A[] = {0, 5, 5, 3, 5, 7, 5}; // True
     int B[] = {0, 5, 5, 3, 5, 1, 5, 7}; // False

     if (MajorNum(A, 7) != -1) printf("A:True\n");
     else printf("A:False\n");

     if (MajorNum(B, 8) != -1) printf("B:True");
     else printf("B:False");

    return 0;
}