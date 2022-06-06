//
// Created by mach4101 on 2022/6/6.
//
//
// Created by mach4101 on 2022/6/6.
//

#include<iostream>
using namespace std;

typedef struct Node {
    struct Node * next;
    int data;
} Node, * LinkedList;

int a[7] = {5, 6, 3,2,1,4, 5};
int b[9] = {0, 1, 2, 3, 4, 2,1,4, 5};
int c[5] = {5, 4, 3, 2, 1};

void Build1(LinkedList & L) {
    LinkedList s, r;
    s = (LinkedList) malloc(sizeof(Node));
    L = s;
    r = L;
    r -> next = NULL;
    for(int i = 0; i < 7; ++i) {
        s = (LinkedList) malloc (sizeof(Node));
        s -> data = a[i];  //测试数组a，b，c只需改这个地方即可
        r -> next = s;
        r = s;
    }
    r -> next = NULL;
}

void Build2(LinkedList & L) {
    LinkedList s, r;
    s = (LinkedList) malloc(sizeof(Node));
    L = s;
    r = L;
    r -> next = NULL;
    for(int i = 0; i < 9; ++i) {
        s = (LinkedList) malloc (sizeof(Node));
        s -> data = b[i];  //测试数组a，b，c只需改这个地方即可
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

int maxv(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int minv(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

// 尾段有一段重合，首先在长的链表上走一段，让两个链表的剩余长度相同，然后一起走，如果发现有相同的节点，则说明不仅有公共节点，而且一直到最后一个节点，这一段都公共节点
void CommonNode(LinkedList L1, LinkedList L2) {
    LinkedList p1 = L1 -> next;
    LinkedList p2 = L2 -> next;
    int len1 = 7, len2 = 9;

    int jump = maxv(len1, len2) - minv(len1, len1);

    if (len1 > len2) {
        while(jump--) {
            p1 = p1 -> next;
        }
    } else {
        while(jump--) {
            p2 = p2 -> next;
        }
    }

    while(p1) {  //开始同步一起跳
        if(p1 -> data == p2 -> data) {  //如果发现有相同的节点，那后面肯定也都是相同的，否则不可能叫Y型公共结点，因为链表中不可能存在X型公共节点（只有一个指针域）
            cout << "公共节点如下：";
            while(p1) {
                cout << p1 -> data << " ";
                p1 = p1 -> next;
            }
        } else {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }

    }
}

int main() {
    LinkedList L1, L2;
    Build1(L1);
    Build2(L2);
    Print(L1);
    Print(L2);
    CommonNode(L1, L2);
    return 0;
}


