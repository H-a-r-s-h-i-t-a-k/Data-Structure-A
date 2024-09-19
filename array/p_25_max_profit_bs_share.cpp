#include "bits/stdc++.h"
using namespace std;

int solveII(vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(2, 0), next(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int bkar = -prices[i] + next[0];
                int skar = 0 + next[1];
                profit = max(bkar, skar);
            }
            else
            {
                int sell = prices[i] + next[1];
                int skar = 0 + next[0];
                profit = max(sell, skar);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}
int solveIII(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int by = 0; by <= 1; by++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int pr = 0;
                if (by)
                {
                    int bykr = -prices[i] + next[0][limit];
                    int skr = 0 + next[1][limit];
                    pr = max(bykr, skr);
                }
                else
                {
                    int sell = prices[i] + next[1][limit - 1];
                    int skr = 0 + next[0][limit];
                    pr = max(sell, skr);
                }
                curr[by][limit] = pr;
            }
        }
        next = curr;
    }
    return next[1][2];
}
int32_t main()
{
    vector<int> p = {10, 22, 5, 75, 65, 80};
    cout << solveII(p) << endl;
    cout << solveIII(p);
}