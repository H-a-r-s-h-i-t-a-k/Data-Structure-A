class Solution
{
public:
  int maximumUniqueSubarray(vector<int> &nums)
  {
    vector<bool> set(10001, false);
    int left = 0, right = 0, sum = 0, maxSum = 0;
    while (right < nums.size())
    {
      while (set[nums[right]])
      {
        sum -= nums[left];
        set[nums[left]] = 0;
        left++;
      }

      set[nums[right]] = 1;
      sum += nums[right];
      right++;
      maxSum = max(maxSum, sum);
    }

    return maxSum;
  }
};
