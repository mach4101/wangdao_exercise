//
// Created by mach4101 on 2022/6/7.
//

#include<iostream>
using namespace std;

typedef struct Node {
    struct Node * next;
    int data;
} Node, * LinkedList;

int a[10] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
int b[5] = {0, 1, 2, 3, 4};
int c[5] = {5, 4, 3, 2, 1};

void Build(LinkedList & L) {
    LinkedList s, r;
    s = (LinkedList) malloc(sizeof(Node));
    L = s;
    r = L;
    r -> next = NULL;
    for(int i = 0; i < 10; ++i) {
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

// 唯一化：由于链表有序，因此重复元素会扎堆，如果一个元素与它后面的元素重复，那么就删除掉后面的元素
LinkedList Unique(LinkedList & L) {
    LinkedList p = L -> next;

    while(p -> next) {  //看看存不存在下一个元素
        if(p -> data == p -> next -> data)  { // 若相同，删掉后面的
            LinkedList q = p -> next;
            p -> next = p -> next -> next;
            free(q);
        } else {
            p = p -> next;
        }
    }
}


int main(){
    LinkedList L;
    Build(L);
    Print(L);
    Unique(L);
    Print(L);
    return 0;
};



