//
// Created by mach4101 on 2022/7/24.
// 指定结点在二叉排序树中的层次：每找一次，层次加一

#include<iostream>
using namespace std;

typedef struct BiNode {
    int data;
    struct BiNode * lchild, * rchild;
}BiNode, * BiTree;

// 是二叉排序树的例子
int a[15] = {10, 5, 3, -1, -1, 8, -1, -1, 15, 13, -1, -1, 20, -1, -1};
int i = 0;
// 创建一棵树
void Build(BiTree & T) {
    int data = a[i ++];  // 改这个地方的a或者b切换样例
    if(data == -1) {
        T = NULL;
    } else {
        T = (BiTree) malloc(sizeof(BiNode));
        T -> data = data;
        T -> lchild = T -> rchild = NULL;
        Build(T -> lchild);
        Build(T -> rchild);
    }
};

void PreOrder(BiTree T) {
    if(T) {
        cout << T -> data << " ";
        PreOrder(T -> lchild);
        PreOrder(T -> rchild);
    }
}

int levelnum = 1;

void Level(BiTree T, int key) {
    if(key < T -> data) {
        // 左子树中找
        if(T -> lchild) {  // 如果左孩子存在，去左子树中找
            levelnum ++;
            Level(T -> lchild, key);
        }
        else {             // 如果左孩子不存在，那么说明没有找到
            levelnum = -1;
        }
    } else if (key > T -> data) {
        if(T -> rchild){
            levelnum ++;
            Level(T -> rchild, key);
        } else {
            levelnum = -1;
        }
    } else { // 如果找到，就返回
        return;
    }


}

int main() {
    BiTree T;
    Build(T);
    Level(T, 5); // 在T中查找5这个关键字
    cout << levelnum << endl;  // 输出层数
    return 0;
}


