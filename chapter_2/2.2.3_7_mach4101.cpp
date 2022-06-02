#include <iostream>
using namespace std;
#define MAX 100

typedef struct SqList{
    int a[MAX];
    int length;
} SqList;

// 合并sqList1与sqList2，然后将合并后的结果返回
SqList process(SqList sqList1, SqList sqList2) {
    SqList sqList3;
    int i = 0, j = 0, cur = 0;                         //i为sqList1的索引，j为sqList2的索引，cur为sqList3的索引
    while(i < sqList1.length && j < sqList2.length) {  //如果i和j都没有越界
        if(sqList1.a[i] < sqList2.a[j]) {              //比较两个表的元素，开始进行二路归并，谁小就先保存谁
            sqList3.a[cur++] = sqList1.a[i++];         //归并之后指针后移
        } else {
            sqList3.a[cur++] = sqList2.a[j++];
        }
    }

    while(i < sqList1.length) {                        //若j已经到头了，i还没有到头，说明sqList1中的元素还没有归并到sqList3中
        sqList3.a[cur++] = sqList1.a[i++];
    }

    while(j < sqList2.length) {                        //也有可能出现i已经到头了，但是j还没有到头
        sqList3.a[cur++] = sqList2.a[j++];
    }

    sqList3.length = cur;                              //更新链表长度
    return sqList3;                                    //返回表
}


int main() {
    SqList sqList1, sqList2;
    for(int i = 0; i < 5; ++i) {
        sqList1.a[i] = i;
    }
    sqList1.length = 5;

    for(int i = 0; i < 5; ++i) {
        sqList2.a[i] = i + 5;
    }
    sqList2.length = 5;

    SqList sqList3;
    sqList3 = process(sqList1, sqList2);

    cout << "处理后的数组为：";
    for(int i = 0; i < sqList3.length; ++i) {
        cout << sqList3.a[i] << " ";
    }
    cout << endl;
    return 0;
}