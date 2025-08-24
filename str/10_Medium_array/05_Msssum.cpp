#include <bits/stdc++.h>
vector<int> maximumsumSubarray(vector<int> &arr, int n)
{
  // app1
  // int maxi=INT_MIN;int cnt=0;int s=0, e=0;
  // for(int i=0;i<n;i++){
  //     int sum=0,c=0;
  //     for(int j=i;j<n;j++){
  //         sum+=arr[j];
  //         c++;

  //    if(maxi<sum){
  //        maxi=sum;
  //        cnt=c;
  //        s=i;
  //        e=j;
  //    }
  //     }
  // }
  // vector<int> ans;

  // for(int i=s;i<=e;i++){
  //     ans.push_back(arr[i]);
  // }
  // return ans;

  // app2

  int s = 0, e = 0;
  int maxsum = INT_MIN;
  int sum = INT_MIN;
  int start = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (sum < 0)
    {
      sum = arr[i];
      start = i;
    }
    else
    {
      sum += arr[i];
    }
    if (maxsum < sum)
    {
      maxsum = sum;
      s = start;
      e = i;
    }
    else if (sum == maxsum && e - s < i - start)
    {
      s = start;
      e = i;
    }
  }
  vector<int> ans;
  for (int i = s; i <= e; i++)
  {
    ans.push_back(arr[i]);
  }
  return ans;
  // Write your code here
}