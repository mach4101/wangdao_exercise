//
// Created by mach4101 on 2022/6/3.
//

#include<iostream>
using namespace std;

typedef struct Node{
    struct Node * next;
    int data;
} Node, * LinkedList;


//使用尾插法建立一个链表, 建立的链表依次从1到n
void Build(LinkedList & L, int n) {
    LinkedList s, r = L;
    //给首节点赋值
    r -> data = 1;
    //若只有一个节点，那就只需要首节点即可，将首节点的指针域设置为NULL
    if (n == 1) {
        r -> next = NULL;
        return;
    }

    //否则就需要使用malloc或者new关键字来动态创建剩余节点，并使用尾插法，尾插法的好处是可以保持顺序，而不是像头插法那样为逆序
    for(int i = 2; i <= n; ++i) {
        s = (LinkedList)malloc(sizeof(Node));
        s -> data = i;
        r -> next = s;
        r = s;
    }
    r -> next = NULL;
}

// 输出链表
void Print(LinkedList L) {
    LinkedList p = L;
    while(p) {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

// 使用递归的方法删除链表中所有值为x的结点(recursive是递归的意思)
void DEL_X_Recursive(LinkedList & L, int x) {
    if(L == NULL)
        return;
    if(L -> data == x) {
        LinkedList p = L;
        L = L -> next;
        free(p);
        DEL_X_Recursive(L, x);
    }
    else
        DEL_X_Recursive(L -> next, x);

}

int main(){
    Node s;
    LinkedList L = &s;
    Build(L, 5);
    cout << "处理前的链表元素：";
    Print(L);
    DEL_X_Recursive(L, 3);
    cout << "处理后的链表元素：";
    Print(L);
}
