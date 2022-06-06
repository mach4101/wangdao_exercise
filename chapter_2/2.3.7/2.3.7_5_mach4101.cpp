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

// 使用头插法进行链表反转
void Reverse_LinkedList(LinkedList & L) {
    LinkedList p = L -> next;  // 从首节点开始
    L -> next = NULL;          // 将头节点单独取出
    while(p) {
        LinkedList q = p -> next;  // q指向p的下一个元素，防止断链
        p -> next = L -> next;     // 头插法1
        L -> next = p;             // 头插法2
        p = q;                     // 借尸还魂
    }
}


int main(){
    LinkedList L;
    Build(L);
    Print(L);
    Reverse_LinkedList(L);
    Print(L);
    return 0;
}

