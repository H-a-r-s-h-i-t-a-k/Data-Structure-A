class Solution
{
public:
  int pivotIndex(vector<int> &nums)
  {
    int leftsum = 0;
    int n = nums.size();
    int rightsum = 0;
    for (int i = 1; i < nums.size(); i++)
    {
      rightsum += nums[i];
    }
    for (int i = 0; i < n; i++)
    {
      if (leftsum == rightsum)
      {
        return i;
      }
      leftsum += nums[i];
      if (i + 1 < n)
      {
        rightsum -= nums[i + 1];
      }
      else
      {
        return -1;
      }
    }
    return 0;
  }
};