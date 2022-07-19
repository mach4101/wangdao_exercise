//
// Created by mach4101 on 2022/7/19.
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



//非递归版本的DFS需要用到栈这个数据结构：
typedef struct Stack{
    int top = -1;
    ArcNode * data[MaxVertexNum];
};

void Push(Stack & S, ArcNode * a) {
    if(S.top == MaxVertexNum - 1) {
        cout << "栈满" << endl;
        return;
    } else {
        S.data[ ++ S.top] = a;
    }
}

void Pop(Stack & S, ArcNode * & a) {
    if(S.top == - 1) {
        cout << "栈空" << endl;
        return;
    } else {
        a = S.data[S.top -- ];
    }
}

bool visited[MaxVertexNum];

void DFS(ALGraph G, int cur) {  // 访问和BFS差不多，只是将栈换成了队列
    cout << G.vertices[cur].data << " ";  // 访问当前的这个结点
    visited[cur] = true;

    Stack stack;
    ArcNode * p = G.vertices[cur].first;
    Push(stack, p);

    while(stack.top != -1) {  // 如果栈不是空的，说明还没访问完
        Pop(stack, p);

        if(!visited[p -> adjvex]) {  // 如果这个结点没有被访问过，首先访问，然后将相连的结点加入到栈中以备访问
            visited[p -> adjvex] = true;
            cout << G.vertices[p -> adjvex].data << " ";

            while(p -> next) {
                Push(stack, p -> next);
                p = p -> next;
            }
        }


    }
}

void DFSTraverse(ALGraph G) {
    for (int i = 0; i < G.vertexnum; ++i) {
        if (visited[i] == false)
            DFS(G, i);
    }
}


int main() {
    ALGraph G;
    CreateGraph(G);
    DFSTraverse(G);
    return 0;
}