/* **************************************************
 * Filename: 2.3.7_2.cpp
 *   Create: 2022-06-01
 *   Author: Wulnut
 * *************************************************/

#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct SqNode {
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

void DeleteElement(SqList &L, ElemType x) {
    while(L != nullptr && L->next != nullptr) {
        if (L->next->data == x) {
            SqNode *temp = L->next;
            if (L->next->next != nullptr) {
                L->next = L->next->next;
            } else {
                L->next = nullptr;
            }
            free(temp);
        } else {
            L = L->next;
        }
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
    DeleteElement(L, 3);
    PrintList(L);
    return 0;
}