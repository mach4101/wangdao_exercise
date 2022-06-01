/* **************************************************
 * Filename: 2.2.3_14.cpp
 *   Create: 2022-05-28
 *   Author: Wulnut
 * *************************************************/

/*
 * 输入样例：
 *    3 4 5
 *    -1 0 9
 *    -25 -10 10 11
 *    2 9 17 30 41
 * 输出结果：
 *  2
 */

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100010;

int l, m, n;
int a[N], b[N], c[N];

int main()
{
    cin >> l >> m >> n;

    for (int i = 0; i < l; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    LL res = 1e18;

    for (int i = 0, j = 0, k = 0; i < l && j < m && k < n;) {

        int x=  a[i], y = b[j], z = c[k];
        res = min( res, (LL)max( max(x, y), z ) - min( min(x, y), z ) );

        if(x <= y && x <= z)
            i++;
        else if(y <= x && y <= z)
            j++;
        else
            k++;
    }

    cout << res * 2 << endl;

    return 0;
}
