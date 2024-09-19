#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int buy = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - buy;
        profit = max(cost, profit);
        buy = min(buy, prices[i]);
    }
    return profit;
}
int main()
{
    vector<int> pr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(pr);
}