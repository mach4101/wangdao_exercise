// Created by mach4101 on 2022/6/24.
//

// 两栈共享空间 [0, maxsize - 1]

#include<iostream>
using namespace std;

#define Maxsize 10
typedef struct DoubleStack {
    int top1;             //第一个栈的栈顶指针
    int top2;             //第二个栈的栈顶指针
    int buffer[Maxsize];  //共享栈
} DoubleStack;

// 将data压入flag所标识的栈中
void Push(DoubleStack & stack, int data, int flag) {  // flag用于标识是哪一个栈，若flag为1表示是第一个栈，2为第二个栈
    if(flag == 1) {
        // 压数据之前需要判断是否已满
        if(stack.top1 + 1 == stack.top2) {
            cout << "栈满了哥" << endl;
            return;
        }

        stack.buffer[++ stack.top1] = data; // 压栈
    } else if(flag == 2) {
        if(stack.top2 - 1 == stack.top1) {
            cout << "栈真满了" << endl;
            return;
        }
        stack.buffer[-- stack.top2] = data; //压栈
    }
}

void Pop(DoubleStack & stack, int & data, int flag) {
    if(flag == 1) {
        //弹数据之前要判断是否为空，如果是空的那就不能弹
        if(stack.top1 == -1) {
            cout << "空的，弹不了哥" << endl;
            return;
        }
        data = stack.buffer[stack.top1 --];
    } else if(flag == 2){
        if(stack.top2 == Maxsize) {
            cout << "空的，弹不了哥" << endl;
            return;
        }

        data = stack.buffer[stack.top2 --];
    }
}

int main() {
    DoubleStack stack;
    stack.top1 = -1;
    stack.top2 = Maxsize;
    Push(stack, 1, 1);
    Push(stack, 2, 1);
    Push(stack, 3, 1);
    Push(stack, 4, 1);
    Push(stack, 5, 1);

    Push(stack, 1, 2);
    Push(stack, 2, 2);
    Push(stack, 3, 2);
    Push(stack, 4, 2);
    Push(stack, 5, 2);

    int data;
    Pop(stack, data, 1);
    cout << data << endl;
    Pop(stack, data, 1);
    cout << data << endl;
    Pop(stack, data, 1);
    cout << data << endl;
    Pop(stack, data, 1);
    cout << data << endl;
    Pop(stack, data, 1);
    cout << data << endl;


    return 0;
}