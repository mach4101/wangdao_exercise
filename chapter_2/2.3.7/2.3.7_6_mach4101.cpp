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

// 使用插入排序的思想，将数组分为两段，前一段是orderd，后一段unordered，依次从后一段中取出一个与元素，插入到前一段中，使前一段保持有序
LinkedList Sort(LinkedList & L) {
    LinkedList p = L -> next, left_head = p -> next;  // left_head是unordered链表部分的头节点
    p -> next = NULL;                                 // 有序的链表和无序的链表断开

    while(left_head) {                                // 依次取出无序链表中的每个节点，将其插入到有序链表中
        LinkedList q = left_head;                     // 首先摘一个节点下来
        left_head = left_head -> next;                // 头节点往后走
        p = L;                                        // 将摘下来的节点插入到有序表中，因此需要和L表中的节点进行对比

                                                      // 开始寻找插入的地方
        while(p -> next && q -> data > p -> next -> data) {
            p = p -> next;
        }
        //将q插入到p的后面
        q -> next = p -> next;
        p -> next = q;
    }
}

int main() {
    LinkedList L;
    Build(L);
    Print(L);
    Sort(L);
    Print(L);
    return 0;
}