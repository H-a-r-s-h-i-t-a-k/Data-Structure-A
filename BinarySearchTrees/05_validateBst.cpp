/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
  bool solve(TreeNode *root, long long minNum, long long maxNum)
  {
    if (root == nullptr)
      return true;
    if (!(root->val > minNum && root->val < maxNum))
      return false;
    else
    {
      bool left = solve(root->left, minNum, root->val);
      bool right = solve(root->right, root->val, maxNum);
      return left && right;
    }
    return false;
  }

public:
  bool isValidBST(TreeNode *root)
  {

    return solve(root, LONG_MIN, LONG_MAX);
  }
};