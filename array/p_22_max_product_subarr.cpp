#include "bits/stdc++.h"
using namespace std;

int maxProduct(vector<int> &nums)
{
    int lp = 1, rp = 1, ans = nums[0];
    double n = nums.size();
    for (int i = 0; i < n; i++)
    {
        lp = lp == 0 ? 1 : lp;
        rp = rp == 0 ? 1 : rp;

        lp *= nums[i];
        rp *= nums[n - 1 - i];
        ans = max(ans, max(lp, rp));
    }
    return ans;
}
int32_t main()
{
    vector<int> n = {2, 1, 4, 5, 2, 6, 6, 2, 54, 534, 2565, 76, 778, 3, 7566, 4, 534, 6565, 567, 45, 4};
    cout << maxProduct(n);
}