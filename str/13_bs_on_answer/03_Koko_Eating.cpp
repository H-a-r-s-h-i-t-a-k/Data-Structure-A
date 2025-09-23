#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int ispossible(vector<int> &nums, int mid, int h)
{
  int n = nums.size();
  int total = 0;
  int i = 0;
  for (; i < n; i++)
  {
    // if (total > h)
    // {
    //   break;
    // }

    int mult =  (nums[i] + mid - 1) / mid;
    total += mult;
  }

  return total;
}
int solve(vector<int> &nums, int h)
{
  int maxNum = nums[0];
  for (auto &item:nums)
  {

    if (item > maxNum)
    {
      maxNum = item;
    }
  }
  int left = 1, right = maxNum;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    int total = ispossible(nums, mid, h);
    if (total <= h)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }

  return left;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, h;
    cin >> n >> h;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
      cin >> nums[i];
    }
    cout << solve(nums, h) << endl;
  }

  return 0;
}