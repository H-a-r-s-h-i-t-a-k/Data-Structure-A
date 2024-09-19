#include "bits/stdc++.h"
using namespace std;
bool find3Numbers(int arr[], int n, int x)
{
    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;

        while (l < r)
        {
            int sum = arr[i] + arr[l] + arr[r];

            if (sum == x)
            {
                return true;
            }
            else if (sum < 0)
            {
                l++;
            }
            else
                r--;
        }
    }

    return false;
}

// leetcode
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;

    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0)
            {
                vector<int> temp = {nums[i], nums[l], nums[r]};
                res.push_back(temp);
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1])
                    l++;
                while (l < r && nums[r] == nums[r + 1])
                    r--;
            }
            else if (sum < 0)
            {
                l++;
            }
            else
                r--;
        }
    }

    return res;
}

int32_t main()
{
    int n = 6, x = 13, arr[] = {1, 4, 45, 6, 10, 8};
    cout << find3Numbers(arr, n, x);
}