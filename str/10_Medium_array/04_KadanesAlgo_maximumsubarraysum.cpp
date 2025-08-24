class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int maxsum = INT_MIN;
    int sum = -1;
    for (int i = 0; i < nums.size(); i++)
    {
      if (sum <= 0)
      {
        sum = nums[i];
      }
      else
      {
        sum += nums[i];
      }
      maxsum = max(maxsum, sum);
    }
    return maxsum;
  }
};