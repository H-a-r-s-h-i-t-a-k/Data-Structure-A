class Solution
{
public:
    int solveR(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        return solveR(n - 1) + solveR(n - 2);
    }
    int solveM(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        // step3
        if (dp[n] != 0)
        {
            return dp[n];
        }
        // step2
        dp[n] = solveR(n - 1) + solveR(n - 2);
        return dp[n];
    }
    int solveT(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        if (n == 0)
            return dp[n];
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int solveS(int n)
    {
        int curr = 1;
        int prev = 0;
        if (n == 0)
        {
            return prev;
        }
        for (int i = 2; i <= n; i++)
        {
            int next = curr + prev;
            prev = curr;
            curr = next;
        }
        return curr;
    }
    int fib(int n)
    {
        //  return solveR(n);
        // vector<int>dp(n+1,0);
        // return solveM(n,dp);
        // return solveT(n);
        return solveS(n);
    }
};