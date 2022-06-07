//
// Created by mach4101 on 2022/6/7.
//


#include<iostream>
using namespace std;

typedef struct Node {
    struct Node * next;
    int data;
} Node, * LinkedList;

int a[7] = {1, 1, 4, 5, 8, 9, 10};
int b[5] = {0, 1, 2, 3, 4};
int c[5] = {5, 4, 3, 2, 1};

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
    for(int i = 0; i < 5; ++i) {
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

// 二路归并链表版，将两个表合并起来，变成新的L1
void MergeList(LinkedList & L1, LinkedList & L2) {
    LinkedList p1 = L1 -> next, p2 = L2 -> next;
    L1 -> next = NULL;
    while(p1 && p2) { // 前提是p1和p2不为空
        if(p1 -> data <= p2 -> data) { // 小的先来

            LinkedList q = p1 -> next; // 防止断链，用q记录下p1的下一个元素
            p1 -> next = L1 -> next;   // p1摘下来，插入到L1的后面，因为题目要求逆序，所以用头插法
            L1 -> next = p1;           // L1把p链上去
            p1 = q;                    // 恢复p的位置
        } else {
            LinkedList q = p2 -> next; // 与上面的逻辑一样
            p2 -> next = L1 -> next;
            L1 -> next = p2;
            p2 = q;
        }
    }

    // 若p1后面还有，那么将p1后面的元素一起接过去
    while(p1) {
        LinkedList q = p1 -> next;
        p1 -> next = L1 -> next;
        L1 -> next = p1;
        p1 = q;
    }

    while(p2) {
        LinkedList q = p2 -> next;
        p2 -> next = L1 -> next;
        L1 -> next = p2;
        p2 = q;
    }
}


int main(){
    LinkedList L1, L2;
    Build1(L1);
    Build2(L2);
    Print(L1);
    Print(L2);
    MergeList(L1, L2);  // 将L1和L2归并，接到L1上
    Print(L1);
    return 0;
};



