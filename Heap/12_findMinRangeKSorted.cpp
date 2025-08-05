

class Node
{
public:
  int val;
  int row;
  int col;
  Node(int val, int r, int c)
  {
    this->val = val;
    row = r;
    col = c;
  }
};
class compare
{
public:
  bool operator()(Node *a, Node *b)
  {
    return a->val > b->val;
  }
};
class Solution
{
public:
  vector<int> smallestRange(vector<vector<int>> &nums)
  {
    priority_queue<Node *, vector<Node *>, compare> minheap;

    int k = nums.size();
    int start = 0, end = INT_MAX;

    int maxi = INT_MIN;

    for (int i = 0; i < k; i++)
    {
      minheap.push(new Node(nums[i][0], i, 0));
      maxi = max(maxi, nums[i][0]);
    }

    while (!minheap.empty())
    {
      Node *front = minheap.top();
      minheap.pop();

      int mini = front->val;

      int r = front->row;
      int c = front->col;
      if (maxi - mini < end - start)
      {
        start = mini;
        end = maxi;
      }
      int n = nums[r].size();
      if (c + 1 < n)
      {
        minheap.push(new Node(nums[r][c + 1], r, c + 1));
        maxi = max(maxi, nums[r][c + 1]);
      }
      else
      {
        break;
      }
    }
    return {start, end};
  }
};
u