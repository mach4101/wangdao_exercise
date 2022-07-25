//
// Created by mach4101 on 2022/7/25.
// 设计算法，从大到小输出二叉排序树中所有值不小于k的关键字

#include<iostream>
using namespace std;
typedef struct BiNode {
    int data;
    struct BiNode * lchild, * rchild;
}BiNode, * BiTree;

// 是二叉排序树的例子
int a[15] = {10, 5, 3, -1, -1, 8, -1, -1, 15, 13, -1, -1, 20, -1, -1};
int i = 0;
// 创建一棵树
void Build(BiTree & T) {
    int data = a[i ++];  // 改这个地方的a或者b切换样例
    if(data == -1) {
        T = NULL;
    } else {
        T = (BiTree) malloc(sizeof(BiNode));
        T -> data = data;
        T -> lchild = T -> rchild = NULL;
        Build(T -> lchild);
        Build(T -> rchild);
    }
};

void PreOrder(BiTree T) {
    if(T) {
        cout << T -> data << " ";
        PreOrder(T -> lchild);
        PreOrder(T -> rchild);
    }
}

// 由于二叉排序树的中序遍历是有序的，因此，可以利用中序遍历来输出，而题目要求从大到小，因此可以使用改进的中序遍历，先打印右子树，再打印左子树
void FindBiggerThanK(BiTree T, int k) {
    if(T) {
        FindBiggerThanK(T -> rchild, k);
        if(T -> data >= k)
            cout << T -> data << " ";
        FindBiggerThanK(T -> lchild, k);
    }
}

int main() {
    BiTree T;
    Build(T);
    int k = 10;
    FindBiggerThanK(T, k);
    return 0;
}

