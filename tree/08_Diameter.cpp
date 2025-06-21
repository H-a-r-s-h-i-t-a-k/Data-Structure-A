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
public:
  int height(TreeNode *root)
  {
    if (root == nullptr)
      return 0;
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
  }
  int solveOne(TreeNode *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    int one = solveOne(root->left);
    int two = solveOne(root->right);
    int three = height(root->left) + 1 + height(root->right);
    int ans = max(one, max(two, three));
    return ans;
  }
  pair<int, int> diameterfast(TreeNode *root)
  {
    pair<int, int> ans;
    if (root == nullptr)
    {
      ans = make_pair(0, 0);
      return ans;
    }

    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);

    int one = left.first;
    int two = right.first;
    int length = left.second + right.second + 1;

    ans = make_pair(0, 0);
    ans.first = max(one, max(two, length));
    ans.second = max(left.second, right.second) + 1;

    return ans;
  }
  int diameterOfBinaryTree(TreeNode *root)
  {
    //    return solveOne(root)-1;

    return diameterfast(root).first - 1;
  }
};