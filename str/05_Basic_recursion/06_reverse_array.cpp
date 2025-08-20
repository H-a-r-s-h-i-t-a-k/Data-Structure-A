
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
vector<int> reverseArray(int n, vector<int> &nums)
{
  int s = 0;
  int e = nums.size() - 1;
  while (s < e)
  {
    swap(nums[s++], nums[e--]);
  }
  return nums;
  // Write your code here.
}
2222222222222222222222222222222222222
void solve(int i, int &n, vector<int> &nums, vector<int> &reverse)
{
  if (i == n)
    return;
  solve(i + 1, n, nums, reverse);
  reverse.push_back(nums[i]);
}

vector<int> reverseArray(int n, vector<int> &nums)
{
  vector<int> reverse;
  solve(0, n, nums, reverse);
  return reverse;
  // Write your code here.
}
