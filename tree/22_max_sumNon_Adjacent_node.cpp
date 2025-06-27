class Solution
{
  pair<int, int> solve(Node *root)
  {
    if (root == nullptr)
    {
      pair<int, int> p = make_pair(0, 0);
      return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> ans;
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first, right.second);

    return ans;
  }

public:
  // Function to return the maximum sum of non-adjacent nodes.
  int getMaxSum(Node *root)
  {
    // code here
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
  }
};