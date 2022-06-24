//
// Created by mach4101 on 2022/6/24.
//

#include<iostream>
using namespace std;

# define Maxsize 100

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


int main() {
    Queue que;
    que.rear = que.front = que.tag = 0; // 全部初始化为零

    int n = 50;
    while(n -- ) {
        Enqueue(que, n);
    }

    n = 25;
    while(n --) {
        int data;
        Dequeue(que, data);
        cout << data << endl;
    }

}

