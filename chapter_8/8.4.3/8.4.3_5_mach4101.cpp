//
// Created by mach4101 on 2022/7/26.
//

#include <iostream>
using namespace std;

bool IsHeap(int A[],int len) {
    if (len % 2 == 0) {
        if (A[len / 2] > A[len]) {
            return false;
            for (int i = len / 2 - 1; i >= 1; i--) {
                if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
                    return false;
            }
        }
        else {
            for (int i = len / 2; i >= 1; i--) {
                if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
                    return false;
            }
        }
        return true;
    }
}

int main()
{
    int A[] = { -1,2,4,5,21,45,21,44,22,87,2,4,8 };
    int B[] = { -1,2,4,3 };
    if (IsHeap(A, 12))
        cout << "是小根堆" << endl;
    else
        cout << "不是小根堆" << endl;
    return 0;
}