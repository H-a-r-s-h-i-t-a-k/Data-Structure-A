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

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
            return 1;
        int comp = ~n;
        int mask = 0;
        while (n != 0)
        {
            n = n >> 1;
            mask = (mask << 1) | 1;
        }
        int res = comp & mask;
        return res;
    }
};