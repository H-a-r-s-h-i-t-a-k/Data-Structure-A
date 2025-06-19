class Solution
{
public:
  int solveR(vector<int> &nums, int idx)
  {
    int n = nums.size();
    if (idx < 0)
    {
      return 0;
    }
    if (idx == 0)
    {
      return nums[0];
    }

    int inc = solveR(nums, idx - 2) + nums[idx];
    int exc = solveR(nums, idx - 1) + 0;
    return max(inc, exc);
  }
  int solveM(vector<int> &nums, int idx, vector<int> &dp)
  {
    if (idx < 0)
    {
      return 0;
    }
    if (idx == 1)
    {
      return nums[0];
    }

    // step3
    if (dp[idx] != INT_MIN)
    {
      return dp[idx];
    }
    int inc = solveM(nums, idx - 2, dp) + nums[idx];
    int exc = solveM(nums, idx - 1, dp) + 0;

    dp[idx] = max(inc, exc);
    return dp[idx];
  }

  int solveT(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= n; i++)
    {
      dp[i] = max(dp[i - 1], (dp[i - 2] + nums[i - 1]));
    }
    return dp[n];
  }

  int solveO(vector<int> &nums)
  {
    int prev1 = 0;
    int prev2 = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      int curr = max((prev1 + nums[i]), prev2);
      prev1 = prev2;
      prev2 = curr;
    }
    return max(prev1, prev2);
  }

  int rob(vector<int> &nums)
  {

    // 1
    int n = nums.size();
    // return solveR(nums,n-1);

    // 2
    //  vector<int>dp(n+1,INT_MIN);
    //  return solveM(nums,n-1,dp);

    // 3
    //  return solveT(nums);

    // 4
    return solveO(nums);
  }
};