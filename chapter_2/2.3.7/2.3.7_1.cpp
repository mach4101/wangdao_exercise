/* **************************************************
 * Filename: 2.3.7_1.cpp
 *   Create: 2022-06-01
 *   Author: Wulnut
 * *************************************************/

#include <iostream>
using namespace std;

typedef struct SqNode{
    int data;
    struct SqNode* next;
}SqNode, *SqList;

SqList CreateList(SqList L) {
    L = (SqList) malloc(sizeof (SqNode));
    SqList s; // 创建节点
    SqList r; // 创建链表

    int val = 0;
    printf("请输入您需要创建的链表(最多1000个)\n");
    scanf("%d", &val);
    getchar();

    while (val != 1000) {
        s = (SqList) malloc(sizeof (SqNode));
        s->data = val;
        s->next = r->next;
        r->next = s;
        r = s;
        scanf("%d", &val);
        getchar();
    }
}

// 递归删除
SqList DeleteElement(SqList *L, int val) {
    SqList s;

    if (*L == nullptr) return nullptr;

    if ((*L)->data == val) {
        s = *L;
        *L = (*L)->next;
        free(s);
        DeleteElement(L, val);
    } else {
        DeleteElement(&((*L)->next), val);
    }
}

void PrintList(SqList L) {
    SqList s;
    s = L;
    while (s != nullptr) {
        printf("%d\n", s->data);
        s = s->next;
    }
    printf("\n");
}

int main() {
    SqList L = nullptr;
    L = CreateList(L);
    PrintList(L);
    DeleteElement(&L, 3);
    PrintList(L);
}
