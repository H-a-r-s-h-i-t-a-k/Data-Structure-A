#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int solve(vector<int> &nums)
{
  int left = 0, right = nums.size() - 1, ans = INT_MAX, index = -1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[left] <= nums[right])
    {
      if (ans > nums[left])
      {
        ans = nums[left];
        index = left;
      }
      return index;
    }

    if (nums[left] <= nums[mid])
    {
      if (ans > nums[left])
      {
        ans = nums[left];
        index = left;
      }
      left = mid + 1;
    }
    else
    {
      if (ans > nums[mid])
      {
        ans = nums[mid];
        index = mid;
      }
      right = mid - 1;
    }
  }
  return index;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
      cin >> nums[i];
    }
    cout << solve(nums) << endl;
  }
  return 0;
}