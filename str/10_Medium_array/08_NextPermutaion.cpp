class Solution
{
public:
  void reversed(vector<int> &nums, int i)
  {
    int s = i, e = nums.size() - 1;
    while (s < e)
    {
      int temp = nums[s];
      nums[s] = nums[e];
      nums[e] = temp;
      s++;
      e--;
    }
  }
  void nextPermutation(vector<int> &nums)
  {
    int ind = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
      if (nums[i] < nums[i + 1])
      {
        ind = i;
        break;
      }
    }
    if (ind == -1)
    {
      reversed(nums, 0);
      return;
    }

    for (int i = n - 1; i > 0; i--)
    {
      if (nums[ind] < nums[i])
      {
        int temp = nums[ind];
        nums[ind] = nums[i];
        nums[i] = temp;
        break;
      }
    }

    reversed(nums, ind + 1);
  }
};