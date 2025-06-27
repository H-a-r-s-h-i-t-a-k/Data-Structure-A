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
  void createMapping(vector<int> &inorder, int &n, map<int, int> &nodeToindex)
  {

    for (int i = 0; i < n; i++)
    {
      nodeToindex[inorder[i]] = i;
    }
  }
  TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &postIndex, int inorderS, int inorderE, map<int, int> &nodeToindex)
  {
    if (postIndex < 0 || inorderS > inorderE)
    {
      return nullptr;
    }

    int ele = postorder[postIndex--];
    int pos = nodeToindex[ele];
    TreeNode *ans = new TreeNode(ele);

    ans->right = solve(inorder, postorder, postIndex, pos + 1, inorderE, nodeToindex);
    ans->left = solve(inorder, postorder, postIndex, inorderS, pos - 1, nodeToindex);
    return ans;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    int n = inorder.size();
    int postIndex = n - 1;
    map<int, int> nodeToindex;
    createMapping(inorder, n, nodeToindex);
    TreeNode *ans = solve(inorder, postorder, postIndex, 0, n - 1, nodeToindex);
    return ans;
  }
};