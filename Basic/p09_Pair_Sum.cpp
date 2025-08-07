#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
  // Write your code here.
  int n = arr.size();
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++)
  {
    vector<int> pair;
    int find = s - arr[i];

    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] == find)
      {
        pair.push_back(min(arr[i], arr[j]));
        pair.push_back(max(arr[i], arr[j]));
        ans.push_back(pair);
      }
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}