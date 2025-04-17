class Solution
{
public:
  int solveO(vector<int> &arr)
  {
    int n = arr.size();
    int prev1 = 0;
    int prev2 = arr[0];
    for (int i = 2; i <= n; i++)
    {
      int curr = max((prev1 + arr[i - 1]), prev2);
      prev1 = prev2;
      prev2 = curr;
    }
    return prev2;
  }

  int maxValue(vector<int> &arr)
  {
    // your code here
    int n = arr.size();
    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
      if (i != 0)
      {
        first.push_back(arr[i]);
      }
      if (i != n - 1)
      {
        second.push_back(arr[i]);
      }
    }

    return max(solveO(first), solveO(second));
  }
};