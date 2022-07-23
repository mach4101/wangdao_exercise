//
// Created by mach4101 on 2022/7/23.
//

#include<iostream>
using namespace std;
#define MaxVertexNum 100

// 边表结点
typedef struct ArcNode{
    int adjvex;
    ArcNode * next;
} ArcNode;

typedef struct VNode {
    char data;
    ArcNode * first;
} VNode, AdjList[MaxVertexNum];

typedef struct ALGraph {
    AdjList vertices;
    int arcnum, vertexnum;
} ALGraph;

int Locate(ALGraph G, char data) {
    for (int i = 0; i < G.vertexnum; ++i) {
        if(G.vertices[i].data == data)
            return i;
    }
}

void CreateGraph(ALGraph & G) {
    cin >> G.vertexnum >> G.arcnum;
    for(int i = 0; i < G.vertexnum; ++i) {
        cin >> G.vertices[i].data;
        G.vertices[i].first = NULL;
    }

    for(int i = 0; i < G.arcnum; ++i) {
        char e1, e2;
        cin >> e1 >> e2;

        int vi = Locate(G, e1);
        int vj = Locate(G, e2);

        ArcNode * p = new ArcNode;
        p -> adjvex = vj;
        p -> next = G.vertices[vi].first;
        G.vertices[vi].first = p;

        p = new ArcNode;
        p -> adjvex = vi;
        p -> next = G.vertices[vj].first;
        G.vertices[vj].first = p;
    }
}

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

int IsQueEmpty(Queue que) {
    return que.rear == que.front && que.tag == 0;
}

bool visited[MaxVertexNum];

void DFS(ALGraph G, int i) {
    visited[i] = true;
    ArcNode * p = G.vertices[i].first;
    while(p) {
        if(!visited[p -> adjvex]) {
            DFS(G, p -> adjvex);
        }
        p = p -> next;
    }
}

void BFS(ALGraph G, int i) {
    // 队列及其初始化工作
    Queue que;
    que.front = que.rear = que.tag = 0;

    // 标记第i个结点为访问过，并将其编号加入队列
    visited[i] = true;
    Enqueue(que, i);

    while(!IsQueEmpty(que)) {
        int x;
        Dequeue(que, x); //取队列头部元素，赋值给x
        ArcNode * p = G.vertices[x].first; // 找到相邻元素

        while(p) {
            if(!visited[p -> adjvex]) { // 若该结点未访问过
                Enqueue(que, p -> adjvex); // 加入队列，标记访问
                visited[p -> adjvex] = true;
            }

            p = p -> next;
        }
    }
}


bool IsExistPath(ALGraph G, int i, int j) {
    // DFS(G, i);  //以i为起点进行DFS
    BFS(G, i);     //以i为起点进行BFS
    return visited[j]; //如果j没有访问过，那么就返回false，否则说明有路径，返回true
}

int main() {
    ALGraph G;
    cout << "请输入相关信息：" << endl;
    CreateGraph(G);

    if(IsExistPath(G, 1, 2)) {
        cout << "有路径" << endl;
    } else {
        cout << "没有路径" << endl;
    }
    return 0;
}

/*
图的相关信息如下：
5 7
a b c d e
a b
a e
b c
b d
b e
c d
d e
* */


