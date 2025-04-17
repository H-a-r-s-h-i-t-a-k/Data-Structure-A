class Solution
{
public:
  int solveR(int n, int x, int y, int z)
  {
    if (n < 0)
      return INT_MIN;
    if (n == 0)
      return 0;

    int segx = solveR(n - x, x, y, z) + 1;
    int segy = solveR(n - y, x, y, z) + 1;
    int segz = solveR(n - z, x, y, z) + 1;
    return max(segx, max(segy, segz));
  }

  int solveM(int n, int x, int y, int z, vector<int> &dp)
  {
    if (n < 0)
      return INT_MIN;
    if (n == 0)
    {
      return 0;
    }

    // step1
    if (dp[n] != -1)
    {
      return dp[n];
    }

    int x_new = solveM(n - x, x, y, z, dp) + 1;
    int y_new = solveM(n - y, x, y, z, dp) + 1;
    int z_new = solveM(n - z, x, y, z, dp) + 1;

    dp[n] = max(x_new, max(y_new, z_new));
    return dp[n];
  }

  int solveT(int n, int x, int y, int z)
  {
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      if ((i - x) >= 0 && dp[i - x] != -1)
      {
        dp[i] = max(dp[i - x] + 1, dp[i]);
      }
      if ((i - y) >= 0 && dp[i - y] != -1)
      {
        dp[i] = max(dp[i - y] + 1, dp[i]);
      }
      if ((i - z) >= 0 && dp[i - z] != -1)
      {
        dp[i] = max(dp[i - z] + 1, dp[i]);
      }
    }

    if (dp[n] < 0)
      return 0;

    return dp[n];
  }

  // Function to find the maximum number of cuts.
  int maximizeTheCuts(int n, int x, int y, int z)
  {
    // Your code here

    // 1
    //  int ans =solveR(n,x,y,z);
    //  if(ans<0)
    //  return 0;
    //  return ans;

    // 2
    //  vector<int> dp(n+1,-1);
    //  int ans=solveM(n,x,y,z,dp);
    //  if(ans<0){
    //      return 0;
    //  }
    //  return ans;

    // 3
    return solveT(n, x, y, z);
  }
};