#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num, ans = 0,
             cin >> num;
    while (num != 0)
    {
        int digit = num % 10;
        ans = (ans * 10) + digit;
        num /= 10;
    }
    cout << ans << endl;
    return 0;
}