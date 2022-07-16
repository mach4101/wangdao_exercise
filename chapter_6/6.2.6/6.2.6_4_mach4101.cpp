//
// Created by mach4101 on 2022/7/16.
//

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

//*****************************************// 邻接矩阵的结构
typedef struct MatrixGraph {
    int Matrix[MaxVertexNum][MaxVertexNum];
    int vertexnum;
} MGraph;

// 根据结点的数据来查找对应的编号
int Locate(ALGraph & G, char x) {
    for(int i = 0; i < G.vertexnum; ++i) {
        if(G.vertices[i].data == x) {
            return i;
        }
    }
    return -1; // 若找不到就返回-1
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

// 深度优先搜索：

bool visited[MaxVertexNum];

void DFS(ALGraph G, int i) { // 从结点i开始进行深度优先遍历
    visited[i] = true;
    ArcNode * p;
    cout << G.vertices[i].data << " ";
    p = G.vertices[i].first;

    while(p) {
        if(!visited[p -> adjvex]) {
            DFS(G, p -> adjvex);
        }
        p = p -> next;
    }
}

void DFSTraverse(ALGraph G) {
    for(int i = 0; i < G.vertexnum; ++i) {
        if(!visited[i])
            DFS(G, i);
    }
}


void Adjency2Matrix(ALGraph & G, MGraph & MG) {
    ArcNode * p;
    for(int i = 0; i < G.vertexnum; ++i) {
        p = G.vertices[i].first;
        while(p) {
            MG.Matrix[i][p -> adjvex] = 1;
            p = p -> next;
        }

    }
}

int main() {
    ALGraph G;
    CreateGraph(G);
    MGraph MG;
    MG.vertexnum = G.vertexnum;
    Adjency2Matrix(G, MG);

    for(int i = 0; i < MG.vertexnum; ++i) {
        for(int j = 0; j < MG.vertexnum; ++j) {
            cout << MG.Matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
