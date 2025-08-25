class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    // app1
    // int maxi=INT_MIN;
    // int n=prices.size();
    // if(n<2)return 0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         int pro=prices[j]-prices[i] ;
    //         maxi=max(maxi,pro);
    //     }
    // }
    // // return maxi;
    // return maxi!=-1?maxi:0;

    int profit = 0, n = prices.size();
    int buy = prices[0];
    for (int i = 1; i < n; i++)
    {
      if (prices[i] < buy)
      {
        buy = prices[i];
      }

      int dif = prices[i] - buy;
      if (dif > profit)
      {
        profit = dif;
      }
    }
    return profit;
  }
};