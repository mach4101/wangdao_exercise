//
// Created by mach4101 on 2022/6/30.
//

// 自上而下，从右到左的遍历顺序，就是将自上而下，自左到右的遍历方式（也就是所谓的层序遍历）逆序一下
#include<iostream>
using namespace std;

// 二叉树使用的是例图中的结构
// 二叉树的前序序列为：ABD##E##CFH##I##G##
typedef struct BiNode {
    char data;  // 数据域
    int tag;   // 标志域
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
        T -> tag = 0;                             // 标志域，表示还没有被访问过
        T -> lchild = NULL;                       // 左右孩子都设置为空
        T -> rchild = NULL;
        Build(T -> lchild);                    // 递归创建左孩子
        Build(T -> rchild);                    // 递归创建右孩子
    }
}

// 栈结构如下 **************************************************
# define MaxSize 100
typedef struct Stack{
    BiNode * data[MaxSize];  // 栈中存放的是指向节点的指针
    int top = -1;            // 栈顶指针
}Stack;

void Push(Stack & S, BiNode * a) {
    if(S.top == MaxSize - 1) {
        cout << "栈满" << endl;
        return;
    } else {
        S.data[ ++ S.top] = a;
    }
}

void Pop(Stack & S, BiNode * & a) {
    if(S.top == - 1) {
        cout << "栈空" << endl;
        return;
    } else {
        a = S.data[S.top -- ];
    }
}

void GetTop(Stack & S, BiNode * & a) {
    if(S.top == - 1) {
        cout << "栈空" << endl;
        return;
    } else {
        a = S.data[S.top];
    }
}
// 判断栈S是否为空，若为空，则返回true，否则为false
int IsStackEmpty(Stack S) {
    return S.top == -1;
}


// 层序遍历还需要使用队列
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

void PrePrint(BiTree T) { // 先序遍历
    if(T) {
        cout << T -> data << " ";
        PrePrint(T -> lchild);
        PrePrint(T -> rchild);
    }

}

void TraverseByReverseLevel(BiTree T) {  // 反层序遍历
    Stack s;
    Queue que;
    InitQueue(que);

    Enqueue(que, T);

    while(!IsQueEmpty(que)) {  // 层序遍历的模板，可以拓展深度优先搜索哦
        BiNode * p;
        Dequeue(que, p); // 出队

        Push(s, p);   // 先不急输出，压栈，以便实现反层序遍历，如果直接输出就是普通的层序遍历

        if(p -> lchild)
            Enqueue(que, p -> lchild);
        if(p -> rchild)
            Enqueue(que, p -> rchild);
    }

    while(!IsStackEmpty(s)) {  // 将栈里面的元素全部拿出来输出
        BiNode * p;
        Pop(s, p);
        cout << p -> data << " ";
    }
}

int main() {
    BiTree T;
    Build(T); // 构建二叉树
    TraverseByReverseLevel(T);
    return 0;
}
