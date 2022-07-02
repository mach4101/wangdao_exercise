//
// Created by mach4101 on 2022/7/2.
//

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

void PreOrder(BiTree T) {
    if(T) {
        cout << T -> data << " ";
        PreOrder(T -> lchild);
        PreOrder(T -> rchild);
    }
}

void MidOrder(BiTree T) {
    if(T) {
        MidOrder(T -> lchild);
        cout << T -> data << " ";
        MidOrder(T -> rchild);
    }
}

// 交换左右子树
void SwapLchildRchild(BiTree T) {
    if(!T) return;

    BiTree tmp = T -> lchild;
    T -> lchild = T -> rchild;
    T -> rchild = tmp;

    SwapLchildRchild(T -> lchild);
    SwapLchildRchild(T -> rchild);
}

int main() {
    BiTree T;
    Build(T);
    cout << "交换前的先序:";
    PreOrder(T);
    cout << "交换前的中序:";
    MidOrder(T);
    cout << endl;

    SwapLchildRchild(T);

    cout << "交换后的先序:";
    PreOrder(T);
    cout << "交换后的中序:";
    MidOrder(T);

}