class Solution
{
public:
  int solveR(int n, vector<int> &days, vector<int> &costs, int idx, vector<int> &dp)
  {
    if (idx >= n)
      return 0;
    if (dp[idx] != -1)
    {
      return dp[idx];
    }

    int one = costs[0] + solveR(n, days, costs, idx + 1, dp);
    int i = idx;
    for (i = idx; i < n && days[i] < days[idx] + 7; i++)
      ;

    int seven = costs[1] + solveR(n, days, costs, i, dp);

    for (i = idx; i < n && days[i] < days[idx] + 30; i++)
      ;
    int thirty = costs[2] + solveR(n, days, costs, i, dp);
    int ans = min(one, min(seven, thirty));

    dp[idx] = ans;
    return dp[idx];
  }

  int mincostTickets(vector<int> &days, vector<int> &costs)
  {

    int n = days.size();
    vector<int> dp(n + 1, -1);
    return solveR(n, days, costs, 0, dp);
  }
};