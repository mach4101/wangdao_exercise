//
// Created by mach4101 on 2022/7/1.
//

#include <iostream>
using namespace std;

// 二叉树使用的是例图中的结构
// 二叉树的前序序列为：ABD##E##CFH##I##G##
typedef struct BiNode {
    char data;  // 数据域
    struct BiNode * lchild, * rchild;
} BiNode, * BiTree;


char A[9] = {'A', 'B' ,'D', 'E', 'C', 'F', 'H', 'I', 'G'};
char B[9] = {'D', 'B', 'E', 'A', 'H', 'F', 'I', 'C', 'G'};

BiTree CreateBiTree(int s1, int e1, int s2, int e2) {//s1和e1表示先序序列的起点和终点，s2和e2表示中序序列的起点和终点
    BiTree T = (BiTree) malloc(sizeof(BiNode));
    T -> data = A[s1]; //创建根节点

    int i;
    for(i = s2; B[i] != A[s1]; ++i); // 空语句循环，目的是为了找到下一个中序遍历的分割线

    int llen = i - s2;        // 得到左子树的长度
    int rlen = e2 - i;        // 得到右子树的长度

    if(llen) {
        // 根据中间节点将中序和先序序列划分开
        T -> lchild = CreateBiTree(s1 + 1, s1 + llen, s2, s2 + llen - 1);
    } else {
        T -> lchild = NULL;
    }

    if(rlen) {
        T -> rchild = CreateBiTree(s1 + llen  + 1, e1 , e2 - rlen + 1, e2);
    } else {
        T -> rchild = NULL;
    }
    return T;
}

// 测试创建效果
void PreOrder(BiTree T) {
    if (T) {
        cout << T -> data << " ";
        PreOrder(T -> lchild);
        PreOrder(T -> rchild);
    }
}

int main() {
    BiTree T;

    T = CreateBiTree(0, 8, 0, 8);

    PreOrder(T);
    return 0;
}

