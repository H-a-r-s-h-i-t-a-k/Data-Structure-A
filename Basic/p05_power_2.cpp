#include <iostream>
#include <climits>
using namespace std;
bool isPowerOfTwo(int n)
{
    int ans = 1;
    for (int i = 0; i <= 30; i++)
    {
        if (ans == n)
            return true;
        if (ans < INT_MAX / 2)
            ans = ans * 2;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    if (isPowerOfTwo(n))
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        bool flag = false;
        while (n != 0)
        {
            if (n & 1)
            {
                if (flag)
                {
                    return false;
                }
                flag = true;
            }
            n = n >> 1;
        }
        return true;
    }
};