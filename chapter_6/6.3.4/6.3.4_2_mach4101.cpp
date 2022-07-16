//
// Created by mach4101 on 2022/7/16.
//

// 对图G进行DFS，并且记录访问的边的数量，若
// 1. 没有未访问完的顶点
// 2. e = n - 1


/*
图的输入样例如下
5 7
a b c d e
a b
a e
b c
b d
b e
c d
d e
树的输入样例如下
5 4
a b c d e
a b
a c
a d
b e
*/


#include<iostream>
using namespace std;

#define MaxVertexNum 100

//*****************************************// 邻接表的结构
// 边表结点
typedef struct ArcNode {
    int adjvex;     //当前结点的编号
    ArcNode * next; //指向下一个结点的指针
} ArcNode;

//顶点表结点
typedef struct VNode {
    char data;                    // 用于存放结点编号所对应的数据
    ArcNode * first;             // 指向与该边相链接的第一个边表结点
} VNode, AdjList[MaxVertexNum];  // 这里的AdjList表示定义了一个数组，数组中的每个元素的类型是VNode型，以后可以直接使用AdjList a; 表示创建一个名为a的数组

// 图结构 Adjacency List -- 邻接表
typedef struct ALGraph {
    AdjList vertices;            // 图包含链接表
    int vertexnum, arcnum;       //结点的个数以及弧的数量
};


// 根据结点值找到结点的编号
int Locate(ALGraph G, char x) {
    for(int i = 0; i < G.vertexnum; ++i) {
        if(G.vertices[i].data == x)
            return i;
    }
    return -1;
}

// 创建图
void CreateGraph(ALGraph & G) {
    cout << "输入结点数和边数，并且用空格来隔开:";
    cin >> G.vertexnum >> G.arcnum;

    // 顶点表信息保存：
    for(int i = 1; i <= G.vertexnum; ++i) {
        cout << "输入第" << i << "个顶点的信息：";
        cin >> G.vertices[i - 1].data;
        G.vertices[i - 1].first = NULL;
    }

    // 边表信息保存：
    for(int i = 1; i <= G.arcnum; ++i) {
        char e1, e2; // 两个结点可以确定一条边
        cout << "输入第" << i << "条边的顶点：";
        cin >> e1 >> e2; //输入边

        // 根据输入的结点值找到其所对应的下标
        int vi = Locate(G, e1);
        int vj = Locate(G, e2);

        // 开始插入, 先将vj插入到vi的后面
        ArcNode * e = new ArcNode; // 申请一个边表结点空间
        e -> adjvex = vj;
        e -> next = G.vertices[vi].first;
        G.vertices[vi].first = e;

        // 再将vi插入到vj的后面
        e = new ArcNode;
        e -> adjvex = vi;
        e -> next = G.vertices[vj].first;
        G.vertices[vj].first = e;
    }
}

bool visited[MaxVertexNum];
int edge = 0; // 记录访问过的边的数量

void DFS(ALGraph G, int x) { // 从顶点x开始进行dfs
    visited[x] = true;
    ArcNode * p = G.vertices[x].first;

    cout << G.vertices[x].data << " ";

    while(p) {
        edge ++;
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
    cout << edge << endl;
    if(edge != 2 * (G.vertexnum - 1) ) {
        return false;
    }
    return true;
}


int main() {
    ALGraph G;
    CreateGraph(G);
    if(GraphIsTree(G)) {
        cout << "树" << endl;
    } else {
        cout << "图" << endl;
    }

    return 0;
}