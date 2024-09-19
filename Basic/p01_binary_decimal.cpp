

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num, i = 0, ans = 0;

    cin >> num;
    while (num != 0)
    {
        int digit = num % 10;
        if (digit == 1)
            ans = ans + pow(2, i);
        num = num / 10;
        i++;
    }
    cout << ans << endl;
    return 0;
}