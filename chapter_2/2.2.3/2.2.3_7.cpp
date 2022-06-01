/* **************************************************
 * Filename: 2.2.3_7.cpp
 *   Create: 2022-05-25
 *   Author: Wulnut
 * *************************************************/

#include <iostream>
using namespace std;

typedef int ElemType;
#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef struct {
    ElemType *elem;
    int length;
}SqList;

int InitOrderList(SqList &L1, SqList &L2, SqList &L3) {
    L1.elem = new ElemType [MAXSIZE];
    L2.elem = new ElemType [MAXSIZE];
    L3.elem = new ElemType [MAXSIZE];

    // 如果元素部分在初始化时有数据，就需要重新分配
    if (!L1.elem || !L2.elem || !L2.elem) return ERROR;

    return OK;
}

int DestroyOrderList(SqList &L1, SqList &L2, SqList &L3) {
    delete L1.elem;
    delete L2.elem;
    delete L3.elem;

    if (L1.elem || L2.elem || L3.elem) return ERROR;

    return OK;
}

int MergeOrderList(SqList &L1, SqList &L2, SqList &L3) {
    if (L1.length + L2.length > L3.length) return ERROR;

    int i = 0, j = 0, k = 0;

    // 从小到大进行排序
    while (i < L1.length && j < L2.length) {
        if (L1.elem[i] <= L2.elem[j]) L3.elem[k ++] = L1.elem[i ++];
        else L3.elem[k ++] = L2.elem[j ++];
    }

    // 将剩下的元素传入列表种
    while (i < L1.length) L3.elem[k ++] = L1.elem[i ++];
    while (j < L2.length) L3.elem[k ++] = L1.elem[i ++];

    L3.length = k;
    return OK;
}

int main() {

    SqList L1, L2, L3;
    InitOrderList(L1, L2, L3);

    L1.elem[0] = 3, L1.elem[1] = 5, L1.elem[2] = 7, L1.elem[3] = 9;
    L2.elem[0] = 2, L2.elem[1] = 4, L2.elem[2] = 6, L2.elem[3] = 8;

    MergeOrderList(L1, L2, L3);

    for (int i = 0; i < L3.length; ++ i) cout << L3.elem[i];

    DestroyOrderList(L1, L2, L3);
    return 0;
}