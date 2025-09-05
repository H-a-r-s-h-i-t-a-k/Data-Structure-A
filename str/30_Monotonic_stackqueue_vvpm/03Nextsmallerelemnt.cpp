
#include <iostream>
#include <stack>
#include <vector>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
  vector<int> nse(n);
  stack<int> stk;
  for (int i = n - 1; i >= 0; i--)
  {
    while (!stk.empty() && stk.top() >= arr[i])
    {
      stk.pop();
    }
    nse[i] = stk.empty() ? -1 : stk.top();
    stk.push(arr[i]);
  }
  return nse;
  // Write your code here.
}