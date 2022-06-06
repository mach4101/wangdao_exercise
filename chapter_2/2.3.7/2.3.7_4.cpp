/* **************************************************
 * Filename: 2.3.7_4.cpp
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

LinkList delete_min(LinkList &L) {
    // L是带头节点的单链表、该函数是删除其中最小值的节点
    LNode* pre = L;
    LNode* p = pre->next;  //p 为工作指针，pre 指向其前驱
    LNode *min_pre = pre, *min_p = p; //保存最小值结点及其前驱

    while (p != nullptr) {
        if (p->data < min_p->data) {
            min_p = p; //找到比之前找到的最小值结点更小的结点
            min_pre = pre;
        }
        pre = p; //继续扫描下一个结点
        p = p->next;
    }

    min_pre->next = min_p->next; //删除最小值结点
    free(min_p);
    return L;
}

void print(LinkList &L) {
    LinkList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    LinkList L;
    init_list(L);
    create_list(L, 5);
    L = delete_min(L);
    print(L);
    return 0;
}
