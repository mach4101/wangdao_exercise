//
// Created by mach4101 on 2022/7/2.
// 计算双分枝节点的个数

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

int Calculate(BiTree T) {
    if(T == NULL)
        return 0;
    // 只要有一个为空，就说明没有双分枝
    if(T -> lchild == NULL || T -> rchild == NULL)
        return Calculate(T -> lchild) + Calculate(T -> rchild);
    // 若左孩子和右孩子都有，那么递归计算
    if(T -> lchild && T -> rchild)
        return Calculate(T -> lchild) + Calculate(T -> rchild) + 1;
}

int main() {
    BiTree T;
    Build(T);
    cout << Calculate(T) << endl;
}
