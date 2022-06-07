//
// Created by mach4101 on 2022/6/7.
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

LinkedList SplitLinkedList(LinkedList & L, LinkedList & A, LinkedList & B) {
    LinkedList p = L -> next, a_ptr = A, b_ptr = B; // 定义p指向L的第一个节点，a_ptr指向A链表的头节点，b_ptr指向B链表的头节点

    // 为了在插入的过程中保持原数组中的次序，因此不能使用头插法，只能用尾插法，定义尾指针
    LinkedList a_tail = A, b_tail = B;

    L -> next = NULL;
    int i = 1;

    while(p) {
        if(i % 2 == 1) { // 将p节点从链表上摘下，然后插入到A中
            LinkedList q = p -> next;  // q为临时指针，防止断链
            a_tail -> next = p;        // 将p接在A链表的尾部
            p -> next = NULL;          // 尾部元素指针域设置为空
            a_tail = p;                // 由于插入了新元素，因此需要更新尾指针
            p = q;                     // p重新接回来
        } else {         // 插入到B链表中
            LinkedList q = p -> next;  // q为临时指针，防止断链
            b_tail -> next = p;        // 将p接在B链表的尾部
            p -> next = NULL;          // 尾部元素指针域设置为空
            b_tail = p;                // 由于插入了新元素，因此需要更新尾指针
            p = q;                     // p重新接回来
        }
        i ++;
    }
}


int main(){
    LinkedList L;

    // 将两个带头节点的链表准备好，然后将L拆分成A和B
    LinkedList A, B;
    A = (LinkedList) malloc (sizeof (Node));
    A -> next = NULL;
    B = (LinkedList) malloc(sizeof (Node));
    B -> next = NULL;


    Build(L);
    Print(L);
    SplitLinkedList(L, A, B);
    Print(A);
    Print(B);
    return 0;
};


