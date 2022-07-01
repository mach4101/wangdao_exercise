//
// Created by mach4101 on 2022/7/1.
// 判断一棵树是否为完全二叉树

#include<iostream>
using namespace std;

// 二叉树使用的是例图中的结构
// 二叉树的前序序列为：ABD##E##CFH##I##G##
typedef struct BiNode {
    char data;  // 数据域
    struct BiNode * lchild, * rchild;
} BiNode, * BiTree;

#define MaxSize 100

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
// 判断是否为完全二叉树：按照从上到下从左到右的顺序遍历，找到第一个没有孩子的节点
// 如果该节点后面的节点存在孩子节点，则说明不是完全二叉树，否则是完全二叉树
bool check(BiTree T) {
    Queue que;
    InitQueue(que);

    Enqueue(que, T);

    int flag = 0; //flag若为零，则说明第一个没有孩子的节点还没找


    while(!IsQueEmpty(que)) {
        BiNode * p = NULL;
        Dequeue(que, p);


        if(p -> lchild == NULL && flag == 0) { // 第一个
            flag = 1;
        } else if (p -> lchild != NULL && flag == 1) { // 如果又出现孩子了
            return false;
        }


        if(p -> lchild) {
            Enqueue(que, p -> lchild);
        }
        if(p -> rchild) {
            Enqueue(que, p -> rchild);
        }

    }
    return true;
}

int main() {
    BiTree T;
    Build(T);

    PreOrder(T); cout << endl;

    if(check(T)) {
        cout << "是完全二叉树" << endl;
    } else {
        cout << "不是完全二叉树" << endl;
    }
}

