
class Solution
{

    int solveR(vector<int> &coins, int sum)
    {
        if (sum == 0)
        {
            return 0;
        }
        if (sum < 0)
        {
            return INT_MAX;
        }
        int ans = INT_MAX, mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++)
        {
            ans = solveR(coins, sum - coins[i]);
            if (ans != mini)
            {
                mini = min(1 + ans, mini);
            }
        }
        return mini;
    }

    int tab(vector<int> &coins, int sum)
    {
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= sum; i++)
        { // amount

            for (int j = 0; j < coins.size(); j++)
            { // coins

                int ele = i - coins[j];

                if ((ele >= 0) && dp[ele] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[ele]);

                } // if
            } // for

        } // for

        if (dp[sum] == INT_MAX)
        {
            return -1;
        }
        return dp[sum];
    }

public:
    int minCoins(vector<int> &coins, int sum)
    {
        // Your code goes here

        // int  ans= solveR(coins,sum);
        //     return ans==INT_MAX?-1:ans;

        return tab(coins, sum);
    }
};