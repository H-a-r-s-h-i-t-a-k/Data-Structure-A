#include <bits/stdc++.h>
vector<int> nextGreaterElement(vector<int> &arr, int n)
{
  // app1
  // vector<int> ans(n,-1);
  //  for(int i=0;i<n;i++){
  //      int element=arr[i];
  //      for(int j=i+1;j<n;j++){
  //          if(arr[j]>element){
  //              ans[i]=arr[j];
  //              break;
  //          }

  //      }

  //  }

  //  return ans;
  // app2

  vector<int> ans(n);
  stack<int> stk;
  for (int i = n - 1; i >= 0; i--)
  {
    int element = arr[i];
    while (stk.size() != 0 && stk.top() <= element)
    {
      stk.pop();
    }
    if (stk.size() == 0)
    {
      ans[i] = -1;
    }
    else
    {
      ans[i] = stk.top();
    }

    stk.push(element);
  }

  return ans;
  // Write your code here.
}