#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k)
{
  // Write your code here
  long long presum = 0;
  int n = nums.size();
  map<long long, int> map;
  int maxi = 0;
  for (int i = 0; i < n; i++)
  {
    presum += nums[i];
    if (presum == k)
    {

      maxi = max(maxi, i + 1);
    }

    int rem = presum - k;

    if (map.find(rem) != map.end())
    {
      int dis = i - map[rem];
      maxi = max(maxi, dis);
    }

    if (map.find(presum) == map.end())
    {
      map[presum] = i;
    }
  }
  return maxi;
}