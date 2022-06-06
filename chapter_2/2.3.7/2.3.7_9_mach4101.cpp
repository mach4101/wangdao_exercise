//
// Created by mach4101 on 2022/6/6.
//

#include<iostream>
using namespace std;

typedef struct Node {
    struct Node * next;
    int data;
} Node, * LinkedList;

int a[5] = {3, 2, 1, 4, 5};
int b[5] = {0, 1, 2, 3, 4};
int c[5] = {5, 4, 3, 2, 1};

void Build(LinkedList & L) {
    LinkedList s, r;
    s = (LinkedList) malloc(sizeof(Node));
    L = s;
    r = L;
    r -> next = NULL;
    for(int i = 0; i < 5; ++i) {
        s = (LinkedList) malloc (sizeof(Node));
        s -> data = a[i];  //测试数组a，b，c只需改这个地方即可
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

// 暴力n方输出
LinkedList SortAndDel(LinkedList & L) {
    LinkedList p = L;

    int len = 0;  // len是链表长度，用来看需要循环多少次，每一次输出一个最小值，并且删除一个节点
    while(p -> next) {
        len++;
        p = p -> next;
    }

    while(len -- ) { // 每次循环删除一个节点
        p = L;
        int minv = p -> next -> data;
        LinkedList min_ptr = p;
        while(p -> next) {
            if(p -> next -> data < minv) {
                minv = p -> next -> data;
                min_ptr = p;
            }
            p = p -> next;
        }
        cout << minv << " ";
        LinkedList q = min_ptr -> next;
        min_ptr -> next = min_ptr -> next -> next;
        free(q);
    }

    free(L);
}

int main() {
    LinkedList L;
    Build(L);
    Print(L);
    SortAndDel(L);
    return 0;
}