//
// Created by mach4101 on 2022/6/17.
//

#include<iostream>
using namespace std;

typedef struct Node {
    struct Node * next;
    int data;
} Node, * LinkedList;

int a[7] = {1, 1, 4, 5, 8, 9, 10};
int b[4] = {4, 5, 8, 9};
int c[5] = {1, 2, 3, 4};

void Build1(LinkedList & L) {
    LinkedList s, r;
    s = (LinkedList) malloc(sizeof(Node));
    L = s;
    r = L;
    r -> next = NULL;
    for(int i = 0; i < 7; ++i) {
        s = (LinkedList) malloc (sizeof(Node));
        s -> data = a[i];  //测试数组a，b，c只需改这个地方即可
        r -> next = s;
        r = s;
    }
    r -> next = NULL;
}

void Build2(LinkedList & L) {
    LinkedList s, r;
    s = (LinkedList) malloc(sizeof(Node));
    L = s;
    r = L;
    r -> next = NULL;
    for(int i = 0; i < 4; ++i) {
        s = (LinkedList) malloc (sizeof(Node));
        s -> data = b[i];  //测试数组a，b，c只需改这个地方即可
        r -> next = s;
        r = s;
    }
    r -> next = NULL;
}

void Print(LinkedList L) {
    LinkedList p = L -> next;
    while(p) {
        cout << p -> data << " ";
        p = p -> next;
    }

    cout << endl;
}

bool check(LinkedList L1, LinkedList L2) {
    int L1_length = 7, L2_length = 4;
    LinkedList p1 = L1 -> next, p2 = L2 -> next;
    while(p1) {
        LinkedList q = p1;                             // 记录p1目前所在的位置
        while(p1 && p2 && p1 -> data == p2 -> data) {  // 若p1 p2为扫描完并且有相同的元素，则一起往后跳
            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        if(p2 == NULL)    //如果p2扫描完了，则说明是L1中连续的序列
            return true;
        p1 = q -> next;   // 否则的话就把p1 往后面跳一格
        p2 = L2 -> next;  // p2归位到首节点
    }
    return false;         // 如果在整个遍历过程中都没有发现有相同的序列，那么返回false
}

int main(){
    LinkedList L1, L2;
    Build1(L1);
    Build2(L2);
    Print(L1);
    Print(L2);


    if(check(L1, L2)) { // 求L1和L2的交集
        cout << "是连续的子序列" << endl;
    } else {
        cout << "不是连续的子序列" << endl;
    }
    return 0;
};
