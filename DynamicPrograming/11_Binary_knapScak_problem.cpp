#include <bits/stdc++.h>

int solveR(vector<int> &weight, vector<int> &value, int &n, int ind, int maxWeight)
{
  //   step 1 base case
  if (ind == 0)
  {
    if (weight[0] <= maxWeight)
    {
      return value[0];
    }
    else
    {
      return 0;
    }
  }

  // step2 normal case  include or not  but must calculate exclude
  int inc = 0;
  if (weight[ind] <= maxWeight)
  {
    inc = value[ind] + solveR(weight, value, n, ind - 1, maxWeight - weight[ind]);
  }
  int exc = solveR(weight, value, n, ind - 1, maxWeight);

  // step3 return max of two
  return max(inc, exc);
}
// Top Down
int solveM(vector<int> &weight, vector<int> &value, int &n, int idx, int maxWeight, vector<vector<int>> &dp)
{
  // step1 base case
  if (idx == 0)
  {
    if (weight[0] <= maxWeight)
    {
      return value[0];
    }
    else
      return 0;
  }

  // step2 use store ans if exists
  if (dp[idx][maxWeight] != -1)
  {
    return dp[idx][maxWeight];
  }
  // step3 normal case and find max of (inc ,exc)
  int inc = 0;
  if (weight[idx] <= maxWeight)
  {
    inc = value[idx] + solveM(weight, value, n, idx - 1, maxWeight - weight[idx], dp);
  }
  int exc = solveM(weight, value, n, idx - 1, maxWeight, dp);

  // step4 store ans
  dp[idx][maxWeight] = max(inc, exc);
  // step5 return store ans
  return dp[idx][maxWeight];
}

// Bottom Up
int solveT(vector<int> &weight, vector<int> &value, int &n, int maxWeight)
{
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
  // step1 base condition
  for (int w = weight[0]; w <= maxWeight; w++)
  {
    if (weight[0] <= w)
    {
      dp[0][w] = value[0];
    }
    else
    {
      dp[0][w] = 0;
    }
  }
  // step2 initialise base dp
  for (int i = 1; i < n; i++)
  {
    for (int w = 0; w <= maxWeight; w++)
    {
      int inc = 0;
      if (weight[i] <= w)
      {
        inc = dp[i - 1][w - weight[i]] + value[i];
      }
      int exc = dp[i - 1][w];
      dp[i][w] = max(inc, exc);
    }
  }
  // step3 iterate remaining part
  return dp[n - 1][maxWeight];
}
int solveS(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
  vector<int> prev(maxWeight + 1, 0);
  vector<int> curr(maxWeight + 1, 0);
  // step2 initialise Ist Row prev
  for (int w = weight[0]; w <= maxWeight; w++)
  {
    if (weight[0] <= w)
    {
      prev[w] = value[0];
    }
    else
    {
      prev[w] = 0;
    }
  }
  //  step3 move forword find curr using prev and upadate curr
  for (int i = 1; i < n; i++)
  {
    for (int w = 0; w <= maxWeight; w++)
    {
      int inc = 0;
      if (weight[i] <= w)
      {
        inc = prev[w - weight[i]] + value[i];
      }
      int exc = prev[w];

      curr[w] = max(inc, exc);
    }
    prev = curr;
  }
  // step4 return prev
  return prev[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  // Write your code here
  // return solveR(weight,value,n,n-1,maxWeight);

  // vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
  // return solveM(weight,value,n,n-1,maxWeight,dp);

  // return solveT(weight,value,n,maxWeight);
  return solveS(weight, value, n, maxWeight);
}