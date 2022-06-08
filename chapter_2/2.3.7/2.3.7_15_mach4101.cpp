//
// Created by mach4101 on 2022/6/8.
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

// 由于两个链表都有序，因此可以使用两个指针分别指向两个链表的表头，谁小谁就往后走，若发现有公共元素，则在L3中插入新节点
void FindCommon(LinkedList & L1, LinkedList & L2) {
    LinkedList p1 = L1 -> next, p2 = L2 -> next, r = L1;

    while(p1 && p2) {
        if(p1 -> data < p2 -> data) { //若不是交集
            LinkedList q = p1 -> next;
            free(p1);
            p1 = q;
        } else if(p1 -> data > p2 -> data) { // 不是交集
            LinkedList q = p2 -> next;
            free(p2);
            p2 = q;
        } else {
            r -> next = p1;
            r = p1;
            p1 = p1 -> next;
            LinkedList q = p2;
            p2 = p2 -> next;
            free(q);
        }
    }

    while(p1) {
        LinkedList q = p1 -> next;
        free(p1);
        p1 = q;
    }

    while(p2) {
        LinkedList q = p2 -> next;
        free(p2);
        p2 = q;
    }

    r -> next = NULL;
    free(L2);
}


int main(){
    LinkedList L1, L2;
    Build1(L1);
    Build2(L2);
    Print(L1);
    Print(L2);

    FindCommon(L1, L2);  // 求L1和L2的交集
    Print(L1);
    return 0;
};



