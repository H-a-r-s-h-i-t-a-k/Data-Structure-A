class Solution
{
public:
  int solvea(int n)
  {
    if (n == 0)
      return 0;

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
      int temp = i * i;
      ans = min(ans, 1 + solvea(n - temp));
    }
    return ans;
  }
  int solveM(int n, vector<int> &dp)
  {
    if (n == 0)
    {
      return 0;
    }
    if (dp[n] != -1)
      return dp[n];

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
      int temp = i * i;
      ans = min(ans, 1 + solveM(n - temp, dp));
    }

    dp[n] = ans;
    return ans;
  }

  int solveT(int n)
  {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j * j <= n; j++)
      {
        int temp = j * j;
        if ((i - temp) >= 0)
        {
          dp[i] = min(dp[i], 1 + dp[i - temp]);
        }
      }
    }
    return dp[n];
  }
  int numSquares(int n)
  {
    return solveT(n);
    // return solvea(n);
    // vector<int> dp(n+1,-1);
    // return solveM(n,dp);
  }
};