#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long num, i = 0, ans = 0;

    cin >> num;
    while (num != 0)
    {
        long long bit = num & 1;
        ans = (bit * pow(10, i)) + ans;
        num = num >> 1;
        i++;
    }
    cout << ans << endl;
    return 0;
}
