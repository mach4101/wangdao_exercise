//
// Created by mach4101 on 2022/7/15.
//

#include <iostream>
using namespace std;

#define MaxVertexNum 100
typedef struct {
    char Vex[MaxVertexNum] = {'a', 'b', 'c', 'd', 'e'}; //顶点表
    int Edge[MaxVertexNum][MaxVertexNum] = {{0, 1, 0, 0, 1}, {1, 0, 1, 1, 1}, {0, 1, 0, 1, 0}, {0, 1, 1, 0, 1}, {1, 1, 0, 1, 0}};
    int vexnum, arcnum; //分别是顶点数和边数
}MGraph;


int map[10][10] = {{0, 1, 0, 0, 1}, {1, 0, 1, 1, 1}, {0, 1, 0, 1, 0}, {0, 1, 1, 0, 1}, {1, 1, 0, 1, 0}};

int main() {
    MGraph graph;
    graph.vexnum = 5;
    graph.arcnum = 7;

    // 打印图结点：
    for(int i = 0; i < graph.vexnum; i ++) {
        for (int j = 0; j < graph.vexnum; j ++ ) {
            cout << graph.Edge[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
