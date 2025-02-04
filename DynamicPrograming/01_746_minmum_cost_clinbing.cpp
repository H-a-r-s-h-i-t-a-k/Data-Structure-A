#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int solveR(vector<int> &cost, int n)
    {

        if (n == 0)
            return cost[0];
        if (n == 1)
        {
            return cost[1];
        }

        return cost[n] + min(solveR(cost, n - 1), solveR(cost, n - 2));
    }
    int solveM(vector<int> &cost, int n, vector<int> dp)
    {
        if (n == 0)
        {
            return cost[0];
        }
        if (n == 1)
        {
            return cost[1];
        } // step3
        if (dp[n] != -1)
        {
            return dp[n];
        }

        dp[n] = cost[n] + min(solveM(cost, n - 1, dp), solveM(cost, n - 2, dp));
        return dp[n];
    }
    int solveT(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 2], dp[n - 1]);
    }

    int solveS(vector<int> &cost)
    {
        int n = cost.size();
        int curr = cost[1];
        int prev = cost[0];
        for (int i = 2; i < n; i++)
        {
            int temp = cost[i] + min(curr, prev);
            prev = curr;
            curr = temp;
        }
        return min(curr, prev);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // return min(solveR(cost,n-1),solveR(cost,n-2));
        // vector<int>dp(n,-1);
        // return min(solveM(cost,n-1,dp),solveM(cost,n-2,dp));
        // return solveT(cost);
        return solveS(cost);
    }
};