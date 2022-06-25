/* 括号匹配 有圆括号、方括号和花括号
 * 算法思路：不管遇到什么括号，只要是左括号就入栈，若遇到右括号，
 *
 * */
#include<iostream>
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

bool match(char * s) {
    Stack stack;
    int i = 0;
    while(s[i] != '\0') {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            Push(stack, s[i]);

        // 若是三个又括号
        else if (s[i] == ')') {
            char tmp;
            Pop(stack, tmp);
            if(tmp != '(') return false;
        } else if(s[i] == ']') {
            char tmp;
            Pop(stack, tmp);
            if(tmp != '[') return false;
        } else if(s[i] == '}') {
            char tmp;
            Pop(stack, tmp);
            if(tmp != '{') return false;
        }

        i ++;
    }

    if(!IsEmpty(stack)) return false;
    return true;
}


int main() {
    char * str = "(()[])";
    if(match(str)) {
        cout << "匹配成功" << endl;
    } else {
        cout << "匹配失败" << endl;
    }

}

