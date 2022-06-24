//
// Created by mach4101 on 2022/6/24.
//
#include<iostream>
using namespace std;

# define Maxsize 100

// 栈相关代码定义
typedef struct Stack{
    int data[Maxsize];  // 栈数组
    int top;        // 栈顶指针
}Stack;

void Push(Stack & S, int a) {
    if(S.top == Maxsize - 1) {
        cout << "栈满" << endl;
        return;
    } else {
        S.data[ ++ S.top] = a;
    }
}

void Pop(Stack & S, int & a) {
    if(S.top == - 1) {
        cout << "栈空" << endl;
        return;
    } else {
        a = S.data[S.top -- ];
    }
}

// 队列相关代码定义
typedef struct Queue {
    int rear, front, tag;
    int buffer[Maxsize];
} Queue;

// 入队
void Enqueue(Queue & que, int data) {   // 将data加入队列
    //判断队列是否已满
    if(que.rear == que.front && que.tag == 1) {
        cout << "塞不下啦！" << endl;
        return;
    }

    que.buffer[que.rear] = data;
    que.rear = (que.rear + 1) % Maxsize;
    que.tag = 1;
}

void Dequeue(Queue & que, int & data) {  // 队列出队，将出队元素的值赋值给data
    // 判断队列是否为空
    if(que.rear == que.front && que.tag == 0) {
        cout << "真没有出的了哥" << endl;
        return;
    }

    data = que.buffer[que.front];
    que.front = (que.front + 1) % Maxsize;
    que.tag = 0;
}

void InverseQueue(Queue & que, Stack & stack) {
    // 队列元素出队，然后入栈，然后出栈，入队
    for(int i = 0; i < 10; ++i) {
        int data;
        Dequeue(que, data);
        Push(stack, data);
    }

    for(int i = 0; i < 10; ++i) {
        int data;
        Pop(stack, data);
        Enqueue(que, data);
    }
}

int main() {
    Stack stack;
    Queue que;

    // 初始化数据结构的数据
    stack.top = -1;
    que.rear = que.front = que.tag = 0;

    //假设队列中的元素是 0到9;
    for(int i = 0; i < 10; ++i) {
        Enqueue(que, i);
    }

    InverseQueue(que, stack);  // 利用stack将que的元素逆置

    // 一个一个出队查看结果：
    for(int i = 0; i < 10; ++i) {
        int data;
        Dequeue(que, data);
        cout << data << endl;
    }
    return 0;
}


