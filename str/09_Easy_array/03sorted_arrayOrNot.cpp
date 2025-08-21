int isSorted(int n, vector<int> a)
{
  int flag = 1;
  for (int i = 1; i < n; i++)
  {
    if (a[i - 1] > a[i])
    {
      flag = 0;
    }
  }
  return flag;
  // Write your code here.
}
