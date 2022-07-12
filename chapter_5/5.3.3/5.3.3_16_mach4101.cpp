//
// Created by mach4101 on 2022/7/11.
//

// 将二叉树的叶子结点用一个但链表串起来
// 对二叉树进行先序遍历可以找到叶子节点的先后次序，pre指向上次访问的叶子结点，p作为访问指针

#include<iostream>
using namespace std;

// 二叉树使用的是例图中的结构
// 二叉树的前序序列为：ABD##E##CFH##I##G##
typedef struct BiNode {
    char data;  // 数据域
    struct BiNode * lchild, * rchild;
} BiNode, * BiTree;

// 使用二叉树的先序序列来构造一颗二叉树，其中#表示指针域为空
char a[] = {'A','B','D','#', '#','E','#','#','C','F','H','#','#','I','#','#','G','#','#'};
int i = 0;
void Build(BiTree & T) {
    char ch =  a[i]; i++;
    if(ch == '#')  // 如果是#，则说明这个节点是空的
        T = NULL;
    else {
        T = (BiTree) malloc(sizeof(BiNode)); // 申请一个节点空间
        T -> data = ch;                           // 为其赋值
        T -> lchild = NULL;                       // 左右孩子都设置为空
        T -> rchild = NULL;
        Build(T -> lchild);                    // 递归创建左孩子
        Build(T -> rchild);                    // 递归创建右孩子
    }
}

// 栈结构如下 **************************************************
# define MaxSize 100
typedef struct Stack{
    BiNode * data[MaxSize];  // 栈中存放的是指向节点的指针
    int top = -1;            // 栈顶指针
}Stack;

void Push(Stack & S, BiNode * a) {
    if(S.top == MaxSize - 1) {
        cout << "栈满" << endl;
        return;
    } else {
        S.data[ ++ S.top] = a;
    }
}

void Pop(Stack & S, BiNode * & a) {
    if(S.top == - 1) {
        cout << "栈空" << endl;
        return;
    } else {
        a = S.data[S.top -- ];
    }
}

void GetTop(Stack & S, BiNode * & a) {
    if(S.top == - 1) {
        cout << "栈空" << endl;
        return;
    } else {
        a = S.data[S.top];
    }
}
// 判断栈S是否为空，若为空，则返回true，否则为false
int IsStackEmpty(Stack S) {
    return S.top == -1;
}

void Leaves2LinkedList(BiTree T, BiNode * & head) {
    Stack s;
    BiNode * pre = NULL, * p = T;

    while(p || !IsStackEmpty(s)) {
        if(p) {
            // 将当前访问到的节点压栈，一路向左
            Push(s, p);

            if(p -> lchild == NULL && p -> rchild == NULL) { // 说明遇到叶子
                if(pre == NULL) { // 如果是第一个叶子节点
                    pre = p;      // 将初始化pre
                    head = p;
                } else {  // 如果不是第一个叶子结点
                    pre -> rchild = p;  // 直接将pre的rchild指向p
                    pre = p;
                }
            }

            p = p -> lchild;
        } else {
            Pop(s, p);  // 取栈顶，向右
            p = p -> rchild;
        }
    }
}

int main() {
    BiTree T;
    Build(T);
    BiNode * head;
    Leaves2LinkedList(T, head);

    // 遍历head所指向的链表
    BiNode * p = head;
    while(p) {
        cout << p -> data << " ";
        p = p -> rchild;
    }
    return 0;
}

