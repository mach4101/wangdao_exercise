//
// Created by mach4101 on 2022/7/26.
// 在链表上进行选择排序

#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node * next;
} Node, * LinkedList;

int a[11] = {0, 21, 11, 9, 3, 15, 17, 3, 25, 7, 21};
void CreateList(LinkedList & L) {
    // 首先创建一个头结点
    L = (LinkedList) malloc(sizeof(Node));
    L -> next = NULL;
    LinkedList r = L;
    // 依次创建剩余结点，并采用尾插法
    for(int i = 0; i < 11; ++i) {
        LinkedList s = (LinkedList) malloc (sizeof(Node));
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
}

 //每一趟选择一个最大的元素，插入到链表的头部
void SelectSortOnLinkedList(LinkedList & L) {
    LinkedList p = L -> next, max, cur, maxpre, curpre; // p指针前面的元素均有序，cur是工作指针，用于遍历序列找最大元素, curpre是cur指针的前驱，maxpre是max指针的前驱，max指向的是当前结点值最大的元素
    L = NULL;
    while(p) {
        cur = p;
        curpre = NULL;
        max = p;
        maxpre = NULL;

        while (cur) {
            if (cur -> data > max -> data) {  // 如果当前找到了最小元素
                max = cur;
                maxpre = curpre;
            }
            curpre = cur;  // 指针后移
            cur = cur -> next;
        }

        if (max == p) {  //如果最大的结点是第一个结点
            p = p -> next;
        } else {
            maxpre -> next = max -> next; // 链表连上，把最大元素的结点单独摘出来
        }
        max -> next = L;
        L = max;
    }
}



int main() {
    LinkedList L;
    CreateList(L);

    cout << "原链表为：";
    Print(L);
    cout << endl;

    SelectSortOnLinkedList(L -> next);
    cout << "排序后的链表为：";
    Print(L);
    cout << endl;
    return 0;
}