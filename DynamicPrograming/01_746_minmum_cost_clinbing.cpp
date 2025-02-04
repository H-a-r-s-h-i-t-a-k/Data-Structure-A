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
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        return min(solveR(cost, n - 1), solveR(cost, n - 2));
    }
};