//
// Created by mach4101 on 2022/6/3.
//

#include<iostream>
using namespace std;

typedef struct Node {
    struct Node * next;
    int data;
} Node, * LinkedList;

int a[5] = {1, 2, 3, 4, 5};

//尾插法建立链表
void Build(LinkedList &L, int n) {
    L = (LinkedList) malloc (sizeof (Node)); //头节点

    LinkedList s, r = L;
    for(int i = 0; i < n; ++i) {
        s = (LinkedList) malloc (sizeof (Node));
        s -> data = a[i];
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

void TraverseReverse(LinkedList L){
    if(L -> next != NULL)
        TraverseReverse(L -> next);
    cout << L -> data << " ";
}

int main() {
    LinkedList L;
    Build(L, 5);
    cout << "处理前的链表元素：";
    Print(L);
    TraverseReverse(L -> next);
}