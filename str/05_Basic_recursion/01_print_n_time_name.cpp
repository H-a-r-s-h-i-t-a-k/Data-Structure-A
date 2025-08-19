void solve(int i, int n, vector<string> &ans)
{
  if (i > n)
  {
    return;
  }
  ans.push_back("harshita");
  solve(i + 1, n, ans);
}

vector<string> printNos(int x)
{
  vector<string> ans;
  solve(1, x, ans);
  return ans;
  // Write Your Code Here
}