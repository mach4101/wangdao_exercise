//
// Created by mach4101 on 2022/7/6.
//

#include<iostream>
using namespace std;

// 二叉树使用的是例图中的结构
// 二叉树的前序序列为：ABD##E##CFH##I##G##
typedef struct BiNode {
    char data;  // 数据域
    struct BiNode * lchild, * rchild;
    int tag = 0;
} BiNode, * BiTree;

// 使用二叉树的先序序列来构造一颗二叉树，其中#表示指针域为空
char a[] = {'A','B','D','#', '#','E','#','#','C','F','H','#','#','I','#','#','G','#','#'};
int i = 0;
void Build(BiTree & T) {
    char ch =  a[i]; i++;
    if(ch == '#')  // 如果是#，则说明这个节点是空的
        T = NULL;
    else {
        T = (BiTree) malloc(sizeof(BiNode)); // 申请一个节点空间
        T -> data = ch;                           // 为其赋值
        T -> lchild = NULL;                       // 左右孩子都设置为空
        T -> rchild = NULL;
        Build(T -> lchild);                    // 递归创建左孩子
        Build(T -> rchild);                    // 递归创建右孩子
    }
}

void LCA(BiTree T, BiNode * p, BiNode * q, BiNode * & r) {
    BiNode * Stack1[20], * Stack2[20];
    // top1是遍历时的栈顶指针，top2是辅助栈栈顶指针
    int top1 = 0, top2 = 0;

    BiNode * tmp = T;

    while(tmp || top1 > 0) {
        // 将左子树全部入栈
        while(tmp) {
            Stack1[++ top1] = tmp;
            tmp = tmp -> lchild;
        }

        // 如果栈一不为空并且已经访问过
        while(top1 != 0 && Stack1[top1] -> tag == 1) {
            // 如果访问到p
            if(Stack1[top1] == p) {
                for(int i = 1; i <= top1; i++) {
                    Stack2[i] = Stack1[i]; // 将栈一中的数据全部复制到辅助栈中
                }
                top2 = top1;
            }
            // 如果访问到q
            if(Stack1[top1] == q)
                // 从栈顶依此往下，找最近的公共祖先
                for(int i = top1; i > 0; i --)
                    for(int j = top2; j > 0; j --)
                        if(Stack1[i] == Stack2[j]) {
                            r = Stack1[i];
                            return;
                        }
            top1 --; // 退栈
        }

        if(top1 != 0) {  // 栈不为空，左边访问完，去右边
            Stack1[top1] -> tag = 1;
            tmp = Stack1[top1] -> rchild;
        }
    }
    return;
}

int main() {
    BiTree T;
    Build(T);

    BiNode * p = T -> rchild -> lchild -> lchild;   // p指针指向'H'
    BiNode * q = T -> rchild -> rchild;             // q指针指向'G'
    BiNode * r = NULL;
    LCA(T, p, q, r);  // 找H和G的最近公共祖先
    if(r)
        cout << r -> data << endl;
    else
        cout << "false" << endl;
    return 0;
}