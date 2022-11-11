/* 括号匹配 有圆括号、方括号和花括号
 * 算法思路：不管遇到什么括号，只要是左括号就入栈，若遇到右括号，则将当前所扫描的字符和栈顶的符号进行比较，如果可以匹配上，那么出栈，继续下一个，否则报错。如果字符串扫描完毕但是栈中依旧有元素，此时也说明有括号没有被匹配上，报错。
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
    while(s[i] != '\0') {                                //遍历串
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')    //左括号入栈
            Push(stack, s[i]);

        // 若是三个右括号
        else if (s[i] == ')') {                          //若是右括号，取出栈顶元素，判断是否和左括号能够匹配，如果不能就直接false
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

        i ++; //下一个
    }

    if(!IsEmpty(stack)) return false; //如果栈没空，说明有多的左括号，直接寄
    return true;
}


int main() {
    char * str = "(()[])";   //待检测的字符串
    if(match(str)) {      //检查是否匹配
        cout << "匹配成功" << endl;
    } else {
        cout << "匹配失败" << endl;
    }

}

