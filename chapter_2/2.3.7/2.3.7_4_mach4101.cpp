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

LinkedList DEL_MIN(LinkedList & L) {
    LinkedList p = L, minp =L -> next; //设置p为第一个元素，minp为当前假定的最小元素

    //p从头节点开始，每次往后看一格，最后minp记录的是最小值的前一个元素，方便删除
    while(p -> next) {
        if (p -> next -> data < minp -> data) {
            minp = p;
        }
        p = p -> next;
    }

    //直接执行对minp的后继节点的删除
    LinkedList q = minp -> next;
    minp -> next = minp -> next -> next;
    free(q);
    return L;
}


int main(){
    LinkedList L;
    Build(L);
    Print(L);
    L = DEL_MIN(L);
    Print(L);
    return 0;
};


