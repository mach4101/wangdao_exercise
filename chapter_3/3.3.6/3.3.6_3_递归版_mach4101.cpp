//
// Created by mach4101 on 2022/6/25.
//

#include<iostream>
using namespace std;

int Pn(int n, int x) {
    if(n == 0)
        return 1;
    else if(n == 1) {
        return 2 * x;
    } else if(n > 1) {
        return 2 * x * Pn(n - 1, x) - 2 * (n - 1) * Pn(n - 2, x);
    }
}

int main() {
    int x = 10;
    int n = 2;
    cout << Pn(n, x) << endl;
}