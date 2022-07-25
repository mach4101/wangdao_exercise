//
// Created by mach4101 on 2022/7/25.
// 求出给定二叉排序树中最小 和 最大的关键字

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

// 二叉排序树的最小值一定在最左边，最大值一定在最右边
void FindMinInSortTree(BiTree T, int & minv) {
    if(T == NULL)
        return;
    else {
        minv = T -> data;
        FindMinInSortTree(T -> lchild, minv);
    }
}

void FindMaxInSortTree(BiTree T, int & maxv) {
    if(T == NULL)
        return;
    else {
        maxv = T -> data;
        FindMaxInSortTree(T -> rchild, maxv);
    }
}

int main() {
    BiTree T;
    int minv = 0;
    int maxv = 0;
    Build(T);
    FindMinInSortTree(T, minv);
    FindMaxInSortTree(T, maxv);
    cout << "最小值：" <<  minv << " " << "最大值：" << maxv << endl;
    return 0;
}


