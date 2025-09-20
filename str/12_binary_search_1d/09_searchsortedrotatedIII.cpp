#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int &target)
{
  int left = 0, right = nums.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }

    if(nums[left]==nums[mid]&&numd[mid]==numd[right]){
      left++;right--;
      continue;
    }
    if (nums[left] <= nums[mid])
    {
      if (nums[left] <= target && target <= nums[mid])
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    else
    {
      if (nums[mid] <= target && nums[right] >= target)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
  }
  return -1;
}
int main()
{
  ;

  int t;
  cin >> t;
  while (t--)
  {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
      cin >> nums[i];
    }
    cout << solve(nums, target) << endl;
  }

  return 0;
}