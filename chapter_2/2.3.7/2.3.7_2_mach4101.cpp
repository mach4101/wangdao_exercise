//
// Created by mach4101 on 2022/6/3.
//

#include<iostream>
using namespace std;

typedef struct Node {
    struct Node * next;
    int data;
} Node, * LinkedList;

int a[5] = {1, 2, 2, 3, 2};

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

void DEL_X_Normal(LinkedList & L, int x){
    LinkedList p = L;                 // 让p指向头节点
    while(p -> next) {                // 然后观察p的下一个节点是否为x
        if(p -> next -> data == x) {  //如果是
            LinkedList q = p -> next; //将p -> next删除
            p -> next = p -> next -> next;
            free(q);
        } else {
            p = p->next;              //若不是则p指向下一个
        }
    }
}

int main() {
    LinkedList L;
    Build(L, 5);
    cout << "处理前的链表元素：";
    Print(L);
    DEL_X_Normal(L, 2);
    cout << "处理后的链表元素：";
    Print(L);
}

