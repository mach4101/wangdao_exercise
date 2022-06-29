//
// Created by mach4101 on 2022/6/29.
//

#include<iostream>
using namespace std;

typedef struct SqTree {
    // 例图中的ABCDEFGHI 使用 123456789 来代替
    int data[16] = {-1, 1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, 8, 9, -1, -1};
};

int LCA(SqTree Tree, int i, int j) {
    // 寻找下标为i, j的最近公共祖先
    if (Tree.data[i] != -1 && Tree.data[j] != -1) {  // 若能满足条件，说明肯定有公共祖先，最起码根节点是，因此如果不满足条件直接返回-1
        while(i != j) {
            if(i > j)
                i = i / 2;
            else
                j = j / 2;
        }
        return Tree.data[i];
    }
    return -1;
}

int main() {
    SqTree Tree;
    cout << LCA(Tree, 12, 13) << endl;  // i和j是对应的下标, data[12] = H， data[13] = I，他们的最近公共祖先是F
    return 0;
}