time efficienct

    class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    priority_queue<int> minheap;
    int n = nums.size();
    for (int i = 0; i < (n - k + 1); i++)
    {
      minheap.push(nums[i]);
    }
    for (int i = (n - k + 1); i < nums.size(); i++)
    {
      if (nums[i] < minheap.top())
      {
        minheap.pop();
        minheap.push(nums[i]);
      }
    }
    return minheap.top();
  }
};


////////////////////////memory efficient
