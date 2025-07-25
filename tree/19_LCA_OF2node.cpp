/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (!root)
    {
      return nullptr;
    }
    if (root == p || root == q)
    {
      return root;
    }

    TreeNode *left = solve(root->left, p, q);
    TreeNode *right = solve(root->right, p, q);

    if (left && right)
    {
      return root;
    }
    else if (left && !right)
    {
      return left;
    }
    else if (!left && right)
    {
      return right;
    }

    else
      return nullptr;
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {

    return solve(root, p, q);
  }
};