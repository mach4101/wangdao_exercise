//
// Created by mach4101 on 2022/6/20.
// 思路：先将链表中的元素一个一个push到栈中，然后再从链表头和栈顶元素依次比较，如果某次发现不等，则说明不是回文，如果一直到结束都没有不等的，则返回true
//

#include<iostream>
using namespace std;

#define MaxSize  100

typedef struct Node {
    struct Node * next;
    char data;
} Node, * LinkedList;

/*
 * 定义栈为空的时候栈顶指针为-1
 * 以后每次Push时，需要先移动指针，然后再将值放进去
 * 取栈顶元素时，直接取top 例如stack[top]，即是栈顶元素
 * */

typedef struct Stack{
    char data[MaxSize];  // 栈数组
    int top = -1;        // 栈顶指针
}Stack;

void Push(Stack & S, char a) {
    if(S.top == MaxSize - 1) {
        cout << "栈满" << endl;
        return;
    } else {
        S.data[ ++ S.top] = a;
    }
}

void Pop(Stack & S, char & a) {
    if(S.top == - 1) {
        cout << "栈空" << endl;
        return;
    } else {
        a = S.data[S.top -- ];
    }
}

char a[4] = {'x', 'x', 'x', 'x'};

void Build(LinkedList & L) {
    LinkedList s, r;
    s = (LinkedList) malloc(sizeof(Node));
    L = s;
    r = L;
    r -> next = NULL;
    for(int i = 0; i < 4; ++i) {
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

bool check (LinkedList L) {
    Stack stk;
    LinkedList p = L -> next;
    while(p) {   // 将链表中的数据全部push到栈中
        Push(stk, p -> data);
        p = p -> next;
    }
    p = L -> next;

    while(p) {
        char a;

        Pop(stk, a);     // 取出栈顶元素
        if (a != p -> data)  // 如果和链表元素不相等
            return false;
        p = p -> next;
    }
    return true;             // 如果在比较过程中未发现异常，则返回true
}

int main(){
    LinkedList L;
    Build(L);
    Print(L);
    if(check(L))
        cout << "是中心对称" << endl;
    else
        cout << "不是中心对称" << endl;
    return 0;
};
