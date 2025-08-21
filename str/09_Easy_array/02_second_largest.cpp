vector<int> getSecondOrderElements(int n, vector<int> a)
{
  int large = a[0];
  int second = INT_MIN;
  for (int i = 1; i < n; i++)
  {
    if (a[i] > large)
    {
      second = large;
      large = a[i];
    }
    else if (a[i] < large && a[i] > second)
    {
      second = a[i];
    }
  }

  int small = a[0];
  int tsmall = INT_MAX;
  for (int i = 1; i < n; i++)
  {
    if (small > a[i])
    {
      tsmall = small;
      small = a[i];
    }
    else if (a[i] > small && a[i] < tsmall)
    {
      tsmall = a[i];
    }
  }

  return {second, tsmall};
  // Write your code here.
}
