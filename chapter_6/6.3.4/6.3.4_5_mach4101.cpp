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
    for (int i = 1; i <= G.vertexnum; ++i) {
        if(G.vertices[i].data == data)
            return i;
    }
}

void CreateGraph(ALGraph & G) {
    cin >> G.vertexnum >> G.arcnum;
    for(int i = 1; i <= G.vertexnum; ++i) {
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

// 深度优先搜索

bool visited[MaxVertexNum];
int dist[MaxVertexNum];

void Path_By_DFS(ALGraph G, int start, int end, int d) {
    visited[start] = true;  // 标记为访问过
    dist[d] = start;        // 记录路径

    if(start == end) {      // 如果目前访问到了最后的结点，那么将保存在dist数组中的元素都输出即可连成一条路径
        for(int i = 0; i <= d; ++i) {
            cout << G.vertices[dist[i]].data << " ";
        }
        cout << endl;
    }

    ArcNode * p = G.vertices[start].first; // 访问邻边
    while(p) {
        if(!visited[p -> adjvex]) {        // 如果没有访问过
            Path_By_DFS(G, p -> adjvex, end, d + 1);  // 访问
        }
        p = p -> next;
    }
    visited[start] = false; //恢复现场，因为可能会有其他路径会经过这个结点
}

/*
 *以下是尝试非递归的代码，有bug
 */

//void Path_By_DFS(ALGraph G, int start, int end) {
//    visited[start] = true;
//    int stack[100];
//    int top = -1;
//    stack[++top] = start;
//    int d = 0;
//    while(top != -1) { // 栈不空
//        int x;
//        x = stack[top--];
//        dist[d++] = x;
//
//        ArcNode * p = G.vertices[x].first;
//        while(p) {
//            if(!visited[p -> adjvex]) {
//                if (p -> adjvex == end) { //如果到了j，那么将栈中的元素全部输出就是路径
//                    dist[d++] = end;
//                    for(int i = 0; i < d; ++i)
//                        cout << G.vertices[dist[i]].data << " ";
//                    cout << endl;
//                    d--;
//                } else {
//                    stack[++top] = p -> adjvex;
//                    visited[p -> adjvex] = true;
//                }
//            }
//            p = p -> next;
//        }
//    }
//}

int main() {
    ALGraph G;
    cout << "输入图的相关信息：" << endl;
    CreateGraph(G);
    int start = Locate(G, 'a'), end = Locate(G, 'd');
    Path_By_DFS(G, start, end, 0); // 从a到d的所有路径
    return 0;
}

/*
5 7
a b c d e
a b
a e
b c
b d
b e
c d
d e
*/