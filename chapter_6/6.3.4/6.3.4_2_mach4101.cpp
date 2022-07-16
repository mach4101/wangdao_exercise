//
// Created by mach4101 on 2022/7/16.
//

// 对图G进行DFS，并且记录访问的边的数量，若
// 1. 没有未访问完的顶点
// 2. e = n - 1


/*

输入样例：
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


#include<iostream>
using namespace std;

#define MaxVertxNum 100


// 邻接表结点
typedef struct ArcNode{
    int adjvex;
    ArcNode * next;
} ArcNode;

// 顶点表结点
typedef struct VNode {
    char data;
    ArcNode * first;
} VNode, AdjList[MaxVertxNum];

// 图结构
typedef struct ALGraph {
   AdjList vertices;
   int arcnum, vertexnum;
} ALGraph;

// 根据结点值找到结点的编号
int Locate(ALGraph G, char x) {
    for(int i = 0; i < G.vertexnum; ++i) {
        if(G.vertices[i].data == x)
            return i;
    }
}

// 创建图
void CreateGraph(ALGraph G) {
    cout << "输入节点数和边的数量：";
    cin >> G.vertexnum >> G.arcnum;

    // 顶点表信息保存：
    for(int i = 1; i <= G.vertexnum; ++i) {
        cout << "输入第" << i << "个顶点的信息：";
        cin >> G.vertices[i - 1].data;
        G.vertices[i - 1].first = NULL;
    }

    // 边表信息保存
    for(int i = 0; i < G.arcnum; ++i) {
        char e1, e2;
        cin >> e1 >> e2;
        int vi = Locate(G, e1);
        int vj = Locate(G, e2);

        ArcNode * p = new ArcNode;
        p -> adjvex = vj;
        p -> next = G.vertices[vj].first;
        G.vertices[vj].first = p;

        p = new ArcNode;
        p -> adjvex = vi;
        p -> next = G.vertices[vi].first;
        G.vertices[vi].first = p;
    }
}


bool visited[MaxVertxNum];
int edge = 0; // 记录访问过的边的数量

void DFS(ALGraph G, int x) { // 从顶点x开始进行dfs
    visited[x] = true;
    ArcNode * p = G.vertices[x].first;

    while(p) {
        edge++;
        if(!visited[p -> adjvex]) {
            DFS(G, p -> adjvex);
        }
        p = p -> next;
    }
}

bool GraphIsTree(ALGraph G) {
    DFS(G, 0); // 从零号顶点开始dfs
    for(int i = 0; i < G.vertexnum; ++i) {
        if(visited[i] == false) {
            return false;
        }
    }

    if(edge != 2 * (G.vertexnum - 1) ) {
        return false;
    }
    return true;
}


int main() {
    ALGraph G;
    CreateGraph(G);
    // 进行dfs
    if(GraphIsTree(G)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}