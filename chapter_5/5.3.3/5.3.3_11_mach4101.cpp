//
// Created by mach4101 on 2022/7/2.
// 对于树中每个元素值为x的节点，删去以其为根的子树，并且释放空间
// 有个地方有疑问，不知道是否需要删除那个值为x的根节点，我考虑的是不删

#include<iostream>
using namespace std;

// 二叉树使用的是例图中的结构
// 二叉树的前序序列为：ABD##E##CFH##I##G##
typedef struct BiNode {
    char data;  // 数据域
    struct BiNode * lchild, * rchild;
} BiNode, * BiTree;

// 二叉树的创建
char a[] = {'A','B','D','#', '#','E','#','#','C','B','H','#','#','I','#','#','G','#','#'};
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

# define MaxSize 100
// 队列结构如下 **************************************************
typedef struct Queue {
    int rear, front, tag;
    BiNode * buffer[MaxSize];  // 存放节点指针
} Queue;

// 入队
void Enqueue(Queue & que, BiNode * data) {   // 将data加入队列
    //判断队列是否已满
    if(que.rear == que.front && que.tag == 1) {
        cout << "塞不下啦！" << endl;
        return;
    }

    que.buffer[que.rear] = data;
    que.rear = (que.rear + 1) % MaxSize;
    que.tag = 1;
}

int IsQueEmpty(Queue que) {
    return que.rear == que.front && que.tag == 0;
}

void Dequeue(Queue & que, BiNode * & data) {  // 队列出队，将出队元素的值赋值给data
    // 判断队列是否为空
    if(que.rear == que.front && que.tag == 0) {
        cout << "真没有出的了哥" << endl;
        return;
    }

    data = que.buffer[que.front];
    que.front = (que.front + 1) % MaxSize;
    que.tag = 0;
}

void InitQueue(Queue & que) {
    que.tag = que.front = que.rear = 0;
}

void DelChild(BiTree & p) {
    // 删除p指针指向的所有节点
    if(p) return;
    DelChild(p -> lchild);  // 递归删除左子树
    DelChild(p -> rchild);  // 递归删除右子树
    free(p);                   // 释放该节点
}

// 先用层序遍历的方式找到值为x的节点的指针，然后删除该节点的所有孩子
void Traverse(BiTree & T, char x) {
    Queue que;
    InitQueue(que);
    Enqueue(que, T);
    BiNode * p;

    while(!IsQueEmpty(que)) {  // 层次遍历
        Dequeue(que, p);

        if(p -> data == x) {  // 找到了值为x的节点
            if (p -> lchild)
                DelChild(p -> lchild);
            if (p -> rchild)
                DelChild(p -> rchild);
            p -> lchild = NULL;
            p -> rchild = NULL;
        }

        if(p -> lchild)
            Enqueue(que, p -> lchild);
        if(p -> rchild)
            Enqueue(que, p -> rchild);
    }
}

int main() {
    BiTree T;
    Build(T);

    PreOrder(T);

    cout << endl;
    char x = 'B';  // 删除例图中值为B的节点的子树

    Traverse(T, x);

    PreOrder(T);
    return 0;
}