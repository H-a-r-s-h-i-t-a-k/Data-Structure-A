class Solution
{
public:
    int solveR(vector<int> &coins, int sum)
    {
        int ans = 0;
        if (sum < 0)
        {
            return 0;
        }
        if (sum == 0)
        {
            return 1;
        }
        for (int i = 0; i < coins.size(); i++)
        {

            ans += solveR(coins, sum -= coins[i]);
        }
        return ans;
    }

    ///////////////////////

    // int solveT(vector<int>& coins,int sum){
    //     vector<int>dp(sum+1,0);
    //     dp[0]=1;

    //     for( int j=0;j<coins.size();j++){

    //     for(int i=coins[j];i<=sum;i++){

    //             dp[i]+=dp[i-coins[j]];

    //         }
    //     }

    //     return dp[sum];

    // }

    int count(vector<int> &coins, int sum)
    {
        // return solveR(coins,sum+1);
        vector<int> dp(sum + 1, -1);
        return solveM(coins, sum + 1, dp);
        // return solveT(coins,sum);
    }
};