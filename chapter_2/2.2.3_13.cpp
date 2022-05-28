/* **************************************************
 * Filename: 2.2.3_13.cpp
 *   Create: 2022-05-28
 *   Author: Wulnut
 * *************************************************/

#include <iostream>
using namespace std;

int missMinNum(int arr[], int n)
{
    int l = 0;
    int r = n;

    while(l < r)
    {
        if(arr[l] == l + 1)//在理想的位置
        {
            l++;
        }
        else if(arr[l] > r || arr[l] <= l || arr[arr[l] - 1] == arr[l])//不合法的数据
        {
            arr[l] = arr[--r];
        }
        else//合法但是没有在理想的位置上
        {
            int temp= arr[l];
            arr[l] = arr[arr[l] - 1];
            arr[temp - 1] = temp;
        }

    }//while

    return l + 1;

}//missMinMun()

int main() {
    int arr[] = {-1, 2, 3, 4};

    printf("%d", missMinNum(arr, 4));

    return 0;
}