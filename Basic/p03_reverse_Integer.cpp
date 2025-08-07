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
class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;

        while (x != 0)
        {
            int digit = x % 10;
            if ((res > INT_MAX / 10) || (res < INT_MIN / 10))
            {
                return 0;
            }
            res = res * 10 + digit;
            x /= 10;
        }
        return res;
    }
};