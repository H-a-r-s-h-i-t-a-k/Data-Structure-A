// 2099. Find Subsequence of Length K With the Largest Sum
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

// Return any such subsequence as an integer array of length k.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: nums = [2,1,3,3], k = 2
// Output: [3,3]
// Explanation:
// The subsequence has the largest sum of 3 + 3 = 6.
// Example 2:

class Solution
{
public:
  vector<int> maxSubsequence(vector<int> &nums, int k)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (minheap.size() < k)
      {
        minheap.push({nums[i], i});
      }
      else
      {
        if (nums[i] > minheap.top().first)
        {
          minheap.pop();
          minheap.push({nums[i], i});
        }
      }
    }
    vector<int> ans;
    while (!minheap.empty())
    {
      pair<int, int> top = minheap.top();
      minheap.pop();
      ans.push_back(top.second);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++)
    {
      ans[i] = nums[ans[i]];
    }
    return ans;
  }
};