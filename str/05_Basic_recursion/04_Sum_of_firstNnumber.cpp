void solve(long long i, long long &n, long long &ans)
{
  if (i > n)
  {
    return;
  }
  solve(i + 1, n, ans);
  ans += i;
}

long long sumFirstN(long long n)
{

  long long ans = 0;
  solve(1, n, ans);
  return ans;
  // Write your code here.
}