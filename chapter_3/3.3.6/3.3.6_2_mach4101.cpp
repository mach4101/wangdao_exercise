//
// Created by mach4101 on 2022/6/25.
//
/* 问题简化
 * 又一个序列前半段是是H，后半段是S
 * 又一个栈道，现在需要利用和这个栈道将S弄到H前面
 * */

#include <iostream>
using namespace std;


#define MaxSize 100

typedef struct Stack{
    char data[MaxSize];  // 栈数组
    int top = -1;        // 栈顶指针
}Stack;
bool IsEmpty(Stack S) {
    return S.top == -1;
}
void Push(Stack & S, char a) {
    if(S.top == MaxSize - 1) {
        cout << "栈满" << endl;
        return;
    } else {
        S.data[ ++ S.top] = a;
    }
}

void Pop(Stack & S, char & a) {
    if(S.top == - 1) {
        cout << "栈空" << endl;
        return;
    } else {
        a = S.data[S.top -- ];
    }
}

void dispatch(Stack stack, char s[]) {
    int cur = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == 'H') {                 // 前半段，压栈
            Push(stack, s[i]);
        } else {                          // 后半段，挪到前面
            s[cur++] = s[i];
        }
    }

    while(!IsEmpty(stack)) {           // 栈不空的话，就把栈里面的前半段弄到后半段去
        char tmp;
        Pop(stack, tmp);
        s[cur++] = tmp;
    }

}

int main() {
    char s[] = "HHHHHHHHHHSSSSSSSSSS";  //假设n等于10，则H和S各有十个

    Stack stack;
    dispatch(stack, s);   //调度

    //输出查看结果
    int i = 0;
    while(s[i] != '\0') {
        cout << s[i] << " ";
        i++;
    }

    return 0;
}