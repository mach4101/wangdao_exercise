//
// Created by mach4101 on 2022/7/12.
// 求孩子兄弟表示的树的高度


#include<iostream>
using namespace std;

typedef struct CSNode {
    char data;
    struct CSNode * firstchild, * nextsibling;
} CSNode, * CSTree;

char a[] = {'A','B','D','#', '#','E','#','#', '#'};
int i = 0;
void build(CSTree & T) {
    char ch = a[i ++];
    if(ch == '#') {
        T = NULL;
    } else {
        T = (CSNode *) malloc(sizeof(CSNode));
        T -> data = ch;
        T -> firstchild = NULL;
        T -> nextsibling = NULL;
        build(T -> firstchild);
        build(T -> nextsibling);
    }
}

int getHeight(CSTree T) {
    if(T == NULL) // 空节点对于高度没有贡献
        return 0;
    else { // 不是空节点，有孩子或者兄弟, 在子女高度+1 与 右兄弟中选出最高的
        return max(getHeight(T -> firstchild) + 1, getHeight(T -> nextsibling));
    }
}

int main() {
    CSTree T;
    build(T);
    cout << getHeight(T) << endl;
    return 0;
}

