//
// Created by mach4101 on 2022/7/11.
//

#include<iostream>
using namespace std;

// 二叉树使用的是例图中的结构
// 二叉树的前序序列为：ABD##E##CFH##I##G##
typedef struct BiNode {
    char data;  // 数据域
    struct BiNode * lchild, * rchild;
    int tag = 0;
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

int getMaxWidth(BiTree T) {
    BiNode * Queue[40];
    int width = -1;
    int front = -1, rear = -1, last = 0;

    Queue[++rear] = T;

    while(front < rear) {
        BiNode * p = Queue[++ front];
        if(p -> lchild)
            Queue[++ rear] = p -> lchild;
        if(p -> rchild)
            Queue[++ rear] = p -> rchild;

        if(front == last) { // 遍历一层结束
            width = max(width, rear - front);
            last = rear;
        }
    }

    return width;
}

int main() {
    BiTree T;
    Build(T);

    cout << getMaxWidth(T) << endl;

    return 0;
}