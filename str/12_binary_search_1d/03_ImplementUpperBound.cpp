int solveUpper(vector<int> &nums, int target)
{
  int index = -1;
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      index = mid;
      left = mid + 1;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  return index;
}