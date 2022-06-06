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

// 将x到y之间的元素给删除掉
LinkedList DEL_X2Y(LinkedList & L, int x, int y) {
    LinkedList p = L;
    while(p -> next) {
        if (p -> next -> data > x && p -> next -> data < y) { // 若在范围内
            LinkedList q = p -> next;                         // q先保存要删除的元素
            p -> next = p -> next -> next;                    // 执行删除操作
            free(q);                                          // 将q释放掉
        }
        p = p -> next;                                        // 看下一个
    }
}

int main() {
    LinkedList L;
    Build(L);
    Print(L);
    DEL_X2Y(L, 1, 4);
    Print(L);
    return 0;
}