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
  TreeNode *solve(vector<int> &preorder, int maxele, int &index)
  {
    if (index >= preorder.size() || preorder[index] > maxele)
    {
      return nullptr;
    }
    TreeNode *newNode = new TreeNode(preorder[index++]);
    newNode->left = solve(preorder, newNode->val, index);
    newNode->right = solve(preorder, maxele, index);
    return newNode;
  }

public:
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    int index = 0;

    TreeNode *ans = solve(preorder, INT_MAX, index);
    return ans;
  }
};
