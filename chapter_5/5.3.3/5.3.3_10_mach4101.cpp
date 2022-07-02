//
// Created by mach4101 on 2022/7/2.
// 求先序遍历的第k个节点的值：可以参考非递归的思路，设置一个自增的变量来实现
// 也可以直接用递归求（参考王道后面的解析）
#include<iostream>
using namespace std;

// 二叉树使用的是例图中的结构
// 二叉树的前序序列为：ABD##E##CFH##I##G##
typedef struct BiNode {
    char data;  // 数据域
    struct BiNode * lchild, * rchild;
} BiNode, * BiTree;

// 二叉树的创建
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

void PreOrder(BiTree T) {
    if(T) {
        cout << T -> data << " ";
        PreOrder(T -> lchild);
        PreOrder(T -> rchild);
    }
}

// 参考非递归的先序遍历思路，设置指针i表示当前正在输出第i个元素，当i=k时将其返回
char PreOrderKth(BiTree T, int k) {
    int i  = 0;
    Stack s;
    BiNode * p = T;
    while(p || !IsStackEmpty(s)) {
        if(p) {
            i ++;
            if(i == k)
                return p -> data;
            Push(s, p);
            p = p -> lchild;
        } else {
            Pop(s, p);
            p = p -> rchild;
        }
    }
}

int main() {
    BiTree T;
    Build(T);
    int k = 3; // 假设要求先序遍历中的第k个节点
    cout << PreOrderKth(T,k) << endl;

    return 0;
}

