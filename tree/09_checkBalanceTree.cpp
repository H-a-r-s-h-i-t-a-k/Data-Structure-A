class Solution
{
public:
  pair<bool, int> solve1(TreeNode *root)
  {
    pair<bool, int> ans;
    if (root == nullptr)
    {
      ans = make_pair(true, 0);
      return ans;
    }

    pair<int, int> left = solve1(root->left);
    pair<int, int> right = solve1(root->right);
    bool leftans = left.first;
    bool rightans = right.first;
    bool cond = abs(left.second - right.second) <= 1;

    ans.first = false;
    ans.second = max(left.second, right.second) + 1;
    if (leftans && rightans && cond)
    {

      ans.first = true;
    }
    return ans;
  }

  bool isBalanced(TreeNode *root)
  {
    return solve1(root).first;
  }
};