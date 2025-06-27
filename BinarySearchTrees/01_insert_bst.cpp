class Solution
{
  TreeNode *solve(TreeNode *&root, int val)
  {
    if (root == NULL)
    {
      root = new TreeNode(val);

      return root;
    }
    if (val < root->val)
    {
      root->left = solve(root->left, val);
    }
    else
    {
      root->right = solve(root->right, val);
    }
    return root;
  }

public:
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    solve(root, val);
    return root;
  }
};