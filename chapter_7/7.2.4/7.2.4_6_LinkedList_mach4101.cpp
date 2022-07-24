//
// Created by mach4101 on 2022/7/24.
//

#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node * next;
} Node, * LinkedList;

int a[11] = {0, 1, 5, 9, 11, 15, 17, 19, 20, 21, 25};


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


int SwitchSearch(LinkedList & L, int key) {
    int i = 0;
    LinkedList p = L -> next, pre = L;

    while(p) {
        if (p -> data == key) {  // 如果找到
            if(i != 0) { // 不是第一个元素，和其前驱交换
                int tmp = p -> data;
                p -> data = pre -> data;
                pre -> data = tmp;
                return i - 1;
            }
            return i;
        }

        // 若没有找到
        p = p -> next;
        pre = pre -> next;
        i = i + 1;
    }
    // 遍历整表，未找到
    return -1;
}

int main() {
    LinkedList L;
    CreateList(L);
    int key = 9;
    cout << "在数组下标为" << SwitchSearch(L, key) << "的位置";
    return 0;
}