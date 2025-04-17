// User function template for C++
class Solution
{
public:
  int solveR(vector<int> &arr, int idx)
  {
    if (idx < 0)
      return 0;
    if (idx == 0)
      return arr[0];

    int inc = solveR(arr, idx - 2) + arr[idx];
    int exc = solveR(arr, idx - 1) + 0;

    return max(inc, exc);
  }
  int solveM(vector<int> &arr, int idx, vector<int> &dp)
  {
    if (idx < 0)
    {
      return 0;
    }
    if (idx == 0)
    {
      return arr[0];
    }
    // step3
    if (dp[idx] != INT_MIN)
    {
      return dp[idx];
    }

    int inc = solveM(arr, idx - 2, dp) + arr[idx];
    int exc = solveM(arr, idx - 1, dp);

    // step2
    dp[idx] = max(inc, exc);
    return dp[idx];
  }

  int solveT(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    dp[1] = arr[0];
    for (int i = 2; i <= n; i++)
    {
      dp[i] = max(dp[i - 1], (dp[i - 2] + arr[i - 1]));
    }
    return dp[n];
  }

  int solveO(vector<int> &arr)
  {
    int prev1 = 0;
    int prev2 = arr[0];
    for (int i = 2; i <= arr.size(); i++)
    {
      int curr = max((prev1 + arr[i - 1]), prev2);
      prev1 = prev2;
      prev2 = curr;
    }
    return prev2;
  }

  // calculate the maximum sum with out adjacent
  int findMaxSum(vector<int> &arr)
  {
    // code here
    int n = arr.size() - 1;

    // 1111111111111111111111111111111111111
    // return solveR(arr,n);
    // 22222222222222222222222222
    // vector<int>dp(n+1,INT_MIN);
    // return solveM(arr,n,dp);

    /// 333333
    // return solveT(arr);
    // 444444
    return solveO(arr);
  }
};