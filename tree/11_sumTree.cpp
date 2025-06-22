class Solution
{
public:
  pair<bool, int> solve(Node *root)
  {
    pair<bool, int> ans = make_pair(false, 0);
    if (root == nullptr)
    {
      ans = make_pair(true, 0);
      return ans;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
      ans = make_pair(true, root->data);
      return ans;
    }
    pair<bool, int> leftsubTree = solve(root->left);
    pair<bool, int> rightsubTree = solve(root->right);

    bool leftans = leftsubTree.first;
    bool rightans = rightsubTree.first;

    bool cond = root->data == (leftsubTree.second + rightsubTree.second);

    if (leftans && rightans && cond)
    {
      ans.first = true;
      ans.second = 2 * root->data;
    }
    //   else{
    //       ans.first=false;
    //   }

    return ans;
  }
  bool isSumTree(Node *root)
  {
    // Your code here

    return solve(root).first;
  }
};