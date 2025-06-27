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
  void createMapping(vector<int> &inorder, map<int, int> &nodeToindex, int n)
  {
    for (int i = 0; i < n; i++)
    {
      nodeToindex[inorder[i]] = i;
    }
  }
  TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, int &n, int inorderStart, int inorderEnd, map<int, int> &nodeToindex)
  {
    if (preorderIndex >= n || inorderStart > inorderEnd)
    {
      return nullptr;
    }
    // step1 fetch root node in preorder
    int element = preorder[preorderIndex++];
    // step2 find position using ansnode to index mapping
    int position = nodeToindex[element];
    // step 3 create ans initialize ansnode node
    TreeNode *ansNode = new TreeNode(element);
    // step 4 normal recursion
    ansNode->left = solve(preorder, inorder, preorderIndex, n, inorderStart, position - 1, nodeToindex);
    ansNode->right = solve(preorder, inorder, preorderIndex, n, position + 1, inorderEnd, nodeToindex);
    // step5 return answernode
    return ansNode;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    int n = inorder.size();
    int preorderIndex = 0;
    map<int, int> nodeToindex;
    createMapping(inorder, nodeToindex, n);
    TreeNode *ans = solve(preorder, inorder, preorderIndex, n, 0, n, nodeToindex);
    return ans;
  }
};