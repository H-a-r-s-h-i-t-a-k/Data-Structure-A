class Solution
{
public:
  int solveR(vector<int> &nums, int target)
  {
    if (target < 0)
      return 0;
    if (target == 0)
      return 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += solveR(nums, target - nums[i]);
    }
    return sum;
  }
  int solveM(vector<int> &nums, int target, vector<int> &dp)
  {
    if (target < 0)
    {
      return 0;
    }
    if (target == 0)
      return 1;

    if (dp[target] != -1)
    {
      return dp[target];
    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += solveM(nums, target - nums[i], dp);
    }
    dp[target] = sum;
    return dp[target];
  }
  int solveT(vector<int> &nums, int target)
  {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= target; i++)
    {
      for (int v = 0; v < nums.size(); v++)
      {
        if (i - nums[v] >= 0)
          dp[i] += dp[i - nums[v]];
      }
    }
    return dp[target];
  }

  int combinationSum4(vector<int> &nums, int target)
  {
    return solveT(nums, target);
    // vector<int> dp(target+1,-1);
    // return solveM(nums,target,dp);
  }
};