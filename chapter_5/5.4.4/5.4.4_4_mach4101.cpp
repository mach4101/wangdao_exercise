//
// Created by mach4101 on 2022/7/12.
//

#include<iostream>
using namespace std;

typedef struct CSNode {
    char data;
    struct CSNode * firstchild, * nextsibling;
} CSNode, * CSTree;

char a[] = {'A','B','D','#', '#','E','#','#','C','F','H','#','#','I','#','#','G','#','#'};
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

int getLeaves(CSTree T) {
    if(T == NULL) {  // 如果结点为空，则没有叶子结点
        return 0;
    } else if(T -> firstchild == NULL) {  // 如果没有孩子，说明是叶子
        return getLeaves(T -> nextsibling) + 1;
    } else {  // 分支结点，去左右两边找
        return getLeaves(T -> firstchild) + getLeaves(T -> nextsibling);
    }
}

int main() {
    CSTree T;
    build(T);
    cout << getLeaves(T) << endl;
    return 0;
}