/* **************************************************
 * Filename: 2.3.7_3.cpp
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

//从链表头部开始遍历，利用头插法生成新链表，再遍历输出新链表的值即可。
SqList headInsert(SqList &head, ElemType value) {//该方法默认链表带有头节点
    SqNode temp = *(SqNode*)malloc(sizeof(SqNode));
    temp.data = value;
    temp.next = head->next;
    head->next = &temp;
}

//利用递归实现。
void printReverse(SqList &L) {
    if (L->next != nullptr) {
        printReverse(L->next); //递归到链表尾部，出栈
    }
    if (L != nullptr) {
        cout << L->data; //输出结果
    }
}

int main() {
    SqList L = nullptr;
    L = CreateList(L);
    printReverse(L);
    return 0;
}