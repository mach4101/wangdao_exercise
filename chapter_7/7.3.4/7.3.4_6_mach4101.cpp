//
// Created by mach4101 on 2022/7/24.
// 编写算法判断所给定的树是否是二叉排序树

#include<iostream>
using namespace std;

#define MaxSize 100

typedef struct BiNode {
    int data;
    struct BiNode * lchild, * rchild;
}BiNode, * BiTree;

// 是二叉排序树的例子
int a[15] = {10, 5, 3, -1, -1, 8, -1, -1, 15, 13, -1, -1, 20, -1, -1};
// 不是二叉排序树的例子
int b[15] = {10, 5, 6, -1, -1, 8, -1, -1, 15, 13, -1, -1, 20, -1, -1};

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

bool IsSortTree(BiTree T) {
    if(T -> lchild && T -> rchild) {
        return T -> lchild -> data <= T -> data && T -> data <= T -> rchild -> data && IsSortTree(T -> lchild) &&
                IsSortTree(T -> rchild);
    }

    if(T -> lchild && T -> rchild == NULL) {
        return T -> lchild -> data <= T -> data && IsSortTree(T -> lchild);
    }

    if(T -> lchild == NULL && T -> rchild) {
        return T -> rchild -> data >= T -> data && IsSortTree(T -> rchild);
    }

    if(T -> lchild == NULL && T -> rchild == NULL)
        return true;

}

int main() {
    BiTree T;
    Build(T);
    if(IsSortTree(T)) {
        cout << "是二叉排序树" << endl;
    } else {
        cout << "不是二叉排序树" << endl;
    }
    return 0;
}

