/* **************************************************
 * Filename: 2.3.7_56.cpp
 *   Create: 2022-06-06
 *   Author: Wulnut
 * *************************************************/

#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct  LNode {
    ElemType data;
    LNode *next;
} LNode, *LinkList;

void init_list(LinkList &L) {
    L = (LinkList) malloc(sizeof (LNode)); // 产生头节点，并使指向此节点
    if (!L) return ; // 存储分配失败
    L->next = nullptr; // 头节点为空
}

// 前插法
void create_list(LinkList &L, int n) {

    L = (LinkList) malloc(sizeof (LNode));
    L->next = nullptr;
    printf("输入%d个数字", n);

    for (int i = n; i > 0; i --) {
        auto p = (LinkList) malloc(sizeof (LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

void print(LinkList &L) {
    LinkList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

LinkList reverse(LinkList &L) {
    LNode *cur_ptr = L->next;
    L->next = nullptr;

    while (cur_ptr) {
        LNode *next_ptr = cur_ptr->next;
        cur_ptr->next = L->next;
        L->next = cur_ptr;
        cur_ptr = next_ptr;
    }

    return L;
}

int main() {
    LinkList L;
    init_list(L);
    create_list(L, 5);
    L = reverse(L);
    print(L);
    return 0;
}