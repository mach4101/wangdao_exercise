//
// Created by mach4101 on 2022/6/29.
//

#include<iostream>
using namespace std;

// 二叉树使用的是例图中的结构
// 二叉树的前序序列为：ABD##E##CFH##I##G##
typedef struct BiNode {
    char data;  // 数据域
    int tag;   // 标志域
    struct BiNode * lchild, * rchild;
} BiNode, * BiTree;

// 改成非递归需要用到栈，栈中的数据类型是BiNode *：
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
int IsEmpty(Stack S) {
    return S.top == -1;
}


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
        T -> tag = 0;                             // 标志域，表示还没有被访问过
        T -> lchild = NULL;                       // 左右孩子都设置为空
        T -> rchild = NULL;
        Build(T -> lchild);                    // 递归创建左孩子
        Build(T -> rchild);                    // 递归创建右孩子
    }
}

// 递归版后序遍历
void TraverseBack(BiTree T) {
    if(T) {
        TraverseBack(T -> lchild);
        TraverseBack(T -> rchild);
        cout << T -> data << " ";
    }
}

// 非递归版本后序遍历
void TraverseBackNonRec(BiTree T) {
    Stack S;
    BiNode * p = T;

    while(p || !IsEmpty(S)) {
        if(p) {  // 步骤一：沿着根的左孩子，依次入栈，直到左孩子为空
            Push(S, p);
            p = p -> lchild;
        } else {  // 读栈顶元素，若其右孩子不空并且未被访问过，右子树执行步骤1（下一个循环）
            GetTop(S, p);
            if(p -> rchild && p -> rchild -> tag  == 0) {
                p = p -> rchild;
            } else {
                Pop(S, p);   // 将节点弹出，并且访问，最后需要将p设置为空，以便于从栈中查看节点
                cout << p -> data << " ";
                p -> tag = 1;
                p = NULL;
            }
        }
    }
}

int main() {
    BiTree T;
    Build(T);
    TraverseBack(T); // 递归版
    TraverseBackNonRec(T); //非递归版

    return 0;
}