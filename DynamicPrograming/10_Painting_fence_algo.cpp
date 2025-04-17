#include <bits/stdc++.h>

#define MOD 1000000007
int add(int a, int b)
{
  return (a % MOD + b % MOD) % MOD;
}
int mul(int a, int b)
{
  return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}
int solveR(int n, int k)
{
  if (n == 1)
    return k;
  if (n == 2)
    return add(k, mul(k, k - 1));

  int ans = add(mul(solveR(n - 2, k), k - 1), mul(solveR(n - 1, k), k - 1));
  return ans;
}

int solveM(int n, int k, vector<int> &dp)
{
  if (n == 1)
    return k;
  if (n == 2)
    return add(k, mul(k, k - 1));

  if (dp[n] != -1)
  {
    return dp[n];
  }
  int ans = add(
      mul(solveM(n - 1, k, dp), k - 1),
      mul(solveM(n - 2, k, dp), k - 1));
  dp[n] = ans;

  return dp[n];
}

int solveO(int n, int k)
{
  int prev2 = k;
  int prev1 = add(k, mul(k - 1, k));
  for (int i = 3; i <= n; i++)
  {
    int curr = add(mul(prev1, k - 1), mul(prev2, k - 1));
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}

int countWays(int n)
{
  int k = 2;
  //  return solveR(n,k);
  // 2
  //  vector<int> dp(n+1,-1);
  //  return solveM(n,k,dp);
  return solveO(n, k);

  // Write your code here
}