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
    // step1 create min heap of k size pair<data,index>
    // step2 insert element in heap upto k  no of element  uisng push and pop
    // step3 fetch index part of heap element  in vectpr
    // step4 sort indexes to keep sequence
    // step5 fetch element using index throught original array


    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    // step1 create min heap of k size pair<data,index>
    int n = nums.size();
    for (int i = 0; i < n; i++)
    { 
      // step2 insert element in heap upto k  no of element  uisng push and pop
     
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
    // step3 fetch index part of heap element  in vectpr
    
    vector<int> ans;
    while (!minheap.empty())
    {
      pair<int, int> top = minheap.top();
      minheap.pop();
      ans.push_back(top.second);
    }
    // step4 sort indexes to keep sequence
    sort(ans.begin(), ans.end());
    // step5 fetch element using index throught original array
    for (int i = 0; i < k; i++)
    {
      ans[i] = nums[ans[i]];
    }
    return ans;
  }
};