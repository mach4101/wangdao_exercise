//
// Created by mach4101 on 2022/7/11.
//

#include<iostream>
using namespace std;

void Pre2Post(char Pre[], int l1, int r1, char Post[], int l2, int r2) {
    if(l1 <= r1) {
        Post[r2] = Pre[l1];
        int half = (r1 - l1) / 2;
        Pre2Post(Pre, l1 + 1, l1 + half, Post, l2, l2 + half - 1);
        Pre2Post(Pre, l1 + half + 1, r1, Post, l2 + half, r2 -1);
    }
}

int main() {
    char Post[8];
    char Pre[8] = "ABDECFG";
    Pre2Post(Pre, 0, 6, Post, 0, 6);
    for(int i = 0; i < 7; ++i) {
        cout << Post[i] << " ";
    }

    return 0;
}