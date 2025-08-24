int missingNumber(vector<int> &a, int N)
{
  int xr = 0;
  for (int i = 1; i <= N; i++)
  {
    xr = xr ^ i;
  }
  for (int i = 0; i < N - 1; i++)
  {
    xr = xr ^ a[i];
  }

  return xr;
  // Write your code here.
}