// Created by mach4101 on 2022/6/24.
/*
 * 使用两个栈来模拟队列，当队列元素入队时，可以将元素push到一号栈中，若需要出队，则将元素全部弹出来，push到二号栈中
 * 此后，若需要入队，则push到一号栈，若需要出队，则从二号栈pop，若二号栈空了，那么就将一号栈中的元素全部弄到二号栈中
 * 当栈一和栈二都空时，队列为空
 * */
#include<iostream>
using namespace std;

# define MaxSize 100

// 栈相关代码定义
typedef struct Stack{
    int data[MaxSize];  // 栈数组
    int top;        // 栈顶指针
}Stack;

bool StackOverflow(Stack S) {
    return S.top == MaxSize -1;
}

bool StackEmpty(Stack S) {
    return S.top == -1;
}

void Push(Stack & S, int a) {
    if(StackOverflow(S)) {
        cout << "栈满" << endl;
        return;
    } else
        S.data[ ++ S.top] = a;
}

void Pop(Stack & S, int & a) {
    if(StackEmpty(S)) {
        cout << "栈空" << endl;
        return;
    } else {
        a = S.data[S.top -- ];
    }
}

bool QueueEmpty(Stack s1, Stack s2) {
    return StackEmpty(s1) && StackEmpty(s2);
}

void Enqueue(Stack & s1, Stack & s2, int data) {
    if(!StackOverflow(s1)) {
        Push(s1, data);
    }

    if(StackOverflow(s1) && !StackEmpty(s2)) {  //一号栈满了，但是二号栈里面有东西，此时若冒然将一号栈中的东西弄到二号栈，则会导致顺序有问题，因此，此时说明队列满了
        cout << "队列满" << endl;
        return;
    }

    if(StackOverflow(s1) && StackEmpty(s2)) { // 一号栈满但是二号栈空，直接弄过去不会有什么顺序问题
        while(!StackEmpty(s1)) {
            int tmp;
            Pop(s1, tmp);
            Push(s2, tmp);
        }
    }
}

void Dequeue(Stack & s1, Stack & s2, int & data) {
    if(!StackEmpty(s2)) {      //s2里面有，直接pop
        Pop(s2, data);
    }

    else if(StackEmpty(s2) && !StackEmpty(s1)) {  //s2空了，但是s1有，全部弄过来
        while(!StackEmpty(s1)) {
            int tmp;
            Pop(s1, tmp);
            Push(s2, tmp);
        }
        Pop(s2, data);
    }

    else if(QueueEmpty(s1, s2)) { //两个栈都没了
        cout << "没了" << endl;
        data = 2147484620;
    }
}

int main() {
    Stack s1, s2;
    s1.top = s2.top = -1;
    Enqueue(s1, s2, 2);
    int data;
    Dequeue(s1, s2, data);
    cout << data << endl;
    return 0;
}

