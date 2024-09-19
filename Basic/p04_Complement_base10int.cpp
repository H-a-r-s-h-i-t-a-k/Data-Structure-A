#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m = n, mask = 0;
    if (n == 0)
        cout << 1 << endl;
    while (m)
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }

    cout << ((~n) & mask) << endl;
    return 0;
}