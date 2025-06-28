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
  void inorderTovector(TreeNode *&root, vector<int> &inorder)
  {
    if (root == nullptr)
      return;
    inorderTovector(root->left, inorder);
    inorder.push_back(root->val);
    inorderTovector(root->right, inorder);
  }

public:
  bool findTarget(TreeNode *root, int k)
  {
    vector<int> inorder;
    inorderTovector(root, inorder);
    int n = inorder.size();
    int s = 0, e = n - 1;
    while (s < e)
    {
      int sum = inorder[s] + inorder[e];
      if (sum < k)
      {
        s++;
      }
      else if (sum > k)
      {
        e--;
      }
      else
      {
        return true;
      }
    }
    return false;
  }
};