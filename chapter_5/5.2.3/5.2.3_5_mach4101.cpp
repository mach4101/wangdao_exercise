//
// Created by mach4101 on 2022/6/29.
//

#include<iostream>
using namespace std;

typedef struct SqTree {
    // 使用字母N来表示无意义的点
    char data[16] = {'N', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'N', 'N', 'N', 'N', 'H', 'I', 'N', 'N'};
};

char LCA(SqTree Tree, int i, int j) {
    // 寻找下标为i, j的最近公共祖先
    if (Tree.data[i] != 'N' && Tree.data[j] != 'N') {  // 若能满足条件，说明肯定有公共祖先，最起码根节点是，因此如果不满足条件直接返回-1
        while(i != j) {                                // i和j谁大谁往上跳
            if(i > j)
                i = i / 2;
            else
                j = j / 2;
        }
        return Tree.data[i];
    }
    return 'N';
}

int main() {
    SqTree Tree;
    cout << LCA(Tree, 12, 13) << endl;  // data[12] = H， data[13] = I，他们的最近公共祖先是F
    return 0;
}