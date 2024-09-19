#include "bits/stdc++.h"
using namespace std;

vector<int> factorial(int N)
{
    vector<int> ans(1, 1);
    while (N > 1)
    {
        int carry = 0, res, size = ans.size();
        for (int i = 0; i < size; i++)
        {
            res = ans[i] * N + carry;
            carry = res / 10;
            ans[i] = res % 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
        N--;
    }
    // code here

    reverse(ans.begin(), ans.end());

    return ans;
}

int32_t main()
{
    vector<int> ans = factorial(100);
    for (auto i : ans)
        cout << i << " ";
}