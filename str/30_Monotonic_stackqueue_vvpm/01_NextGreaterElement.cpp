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

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    // step1 :traverse from last element
    // step2 :push stack to order make decreasing fashion
    // step3 :curr element >= stk.top then pop()
    // step4 :curr element->nextGreaterelement=stk.top(); -1 or any arr value;

    unordered_map<int, int> nge;
    stack<int> stk;
    int c1 = 0;
    int n = nums2.size();
    for (int i = n - 1; i >= 0; i--)
    {
      while (!stk.empty() && nums2[i] >= stk.top())
      {
        stk.pop();
      }

      nge[nums2[i]] = stk.empty() ? -1 : stk.top();

      stk.push(nums2[i]);
    }

    vector<int> ans;
    for (auto &ele : nums1)
    {
      ans.push_back(nge[ele]);
    }

    return ans;
  }
};