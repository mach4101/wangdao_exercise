// Created by mach4101 on 2022/7/24.
// 判断一课二叉树是否是高度平衡的二叉树
#include<iostream>
using namespace std;

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
    int data = b[i ++];  // 改这个地方的a或者b切换样例
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

int Height(BiTree T) {
    if(T == NULL)
        return 0;
    return max(Height(T -> lchild), Height(T -> rchild)) + 1;
}

// 算法思路：（王道答案）
/* 1. 若T为空，高度为0，balance=1
 * 2. 若T仅有根结点，高度为1，balance=1
 * 3. 对左右子树递归运算，返回左右子树的平衡标志以及高度，T的高度是子树的高度加1，如果高度相差大于1，那么balance=0
 * 如果高度相差小于等于一，且左右子树的balance都为1的时，balance = 1，否则balance = 0
 * */
void IsBST(BiTree T, int & balance, int & height) {
    int left_balance, right_balance, left_height, right_height;
    if(T == NULL) { // T为空
        balance = 1;
        height = 0;
    }
    else if(T -> lchild == NULL && T -> rchild == NULL) { // T不为空，但是左右子树都是空的
        balance = 1;
        height = 1;
    } else { //其他情况
        IsBST(T -> lchild, left_balance, left_height);
        IsBST(T -> rchild, right_balance, right_height);

        height = (left_height > right_height) ? left_height + 1 : right_height + 1; // 子树的最大高度加一就是当前结点的最大高度

        if(abs(left_height - right_height) > 2) {
            balance = 0;
        } else {
            balance = left_balance && right_balance;
        }
    }

}

int main() {
    BiTree T;
    Build(T);

    int balance = 0, height = 0;
    IsBST(T, balance, height);
    if(balance) {
        cout << "是平衡树" << endl;
    } else {
        cout << "不是平衡树" << endl;
    }
    return 0;
}

