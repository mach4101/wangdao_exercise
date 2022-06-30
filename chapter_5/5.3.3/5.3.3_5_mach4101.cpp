//
// Created by mach4101 on 2022/6/30.
//
// 算法思路，采用另一套层序遍历的模板，来记录一共有多少层
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

int maxv(int a, int b) {
    return a > b ? a : b;
}

// 递归求树高
int GetHeight(BiTree T) {
    if(T == NULL)
        return 0;
    return maxv(GetHeight(T -> lchild), GetHeight(T -> rchild)) + 1;
}

# define MaxSize 100

// 非递归求树高
int GetHeightNonRec(BiTree T) {
    int front = -1, rear = -1;  // 队头和队尾指针
    int last = 0, level = 0;    // last是当前层的最右边节点，level就是层号

    BiNode * Que[MaxSize];
    Que[++ rear] = T;  // 根节点入队
    BiNode * p;

    while(front < rear) {
        p = Que[++ front]; //出队
        if(p -> lchild)
            Que[++ rear] = p -> lchild;
        if(p -> rchild)
            Que[++ rear] = p -> rchild;

        if(front == last) {  // 重点，当front到达了last后，说明这一层已经结束了
            level ++;        // 手动模拟下更容易理解
            last = rear;
        }
    }

    return level;
}

int main() {
    BiTree T;
    Build(T);
    // 计算二叉树的高度
    cout << GetHeight(T) << endl; // 递归版
    cout << GetHeightNonRec(T) << endl;  // 非递归版
    return 0;
}

