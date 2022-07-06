//
// Created by mach4101 on 2022/7/6.
// 查找值为x的节点，并且编写算法打印值为x的所有祖先节点
// 也就是要输出，从根节点到x节点路径上的所有节点
// 本算法使用的是递归版本，非递归版本王道课后书有所描述

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

void PreOrder(BiTree T) {
    if(T) {
        cout << T -> data << " ";
        PreOrder(T -> lchild);
        PreOrder(T -> rchild);
    }
}

bool FindAns(BiTree T, char x) { // 查找值为x的所有祖先
    if(T -> data == x) {  // 如果找到，那么就向上层返回为true
        return true;
    }

    if(T -> lchild) {    // 若有左子树，就到左子树中找
        if(FindAns(T -> lchild, x)) {  // 若左子树中存在，就输出，并返回true给上层
            cout << T -> data << " ";
            return true;
        }

    }

    if(T -> rchild) {   // 若有右子树，就到右子树中找
        if(FindAns(T -> rchild, x)) {  // 若右子树中存在，就输出，并返回true给上层
            cout << T -> data << " ";
            return true;
        }
    }


}

int main() {
    BiTree T;
    Build(T);
    char x = 'H';

    FindAns(T, x);  // 查找值为x的所有祖先节点

    return 0;
}