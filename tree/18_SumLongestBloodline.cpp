class Solution
{
public:
  void solve(Node *root, int len, int &maxlen, int sum, int &maxsum)
  {
    if (!root)
    {
      if (len > maxlen)
      {
        maxlen = len;
        maxsum = sum;
      }
      else
      {
        if (len == maxlen)
        {
          maxsum = max(sum, maxsum);
        }
      }
      return;
    }
    sum += root->data;
    solve(root->left, len + 1, maxlen, sum, maxsum);
    solve(root->right, len + 1, maxlen, sum, maxsum);
  }

  int sumOfLongRootToLeafPath(Node *root)
  {
    if (root == nullptr)
    {
      return 0;
    }
    int len = 0, maxlen = 0;
    int sum = 0, maxsum = 0;
    solve(root, len, maxlen, sum, maxsum);
    return maxsum;
  }
};