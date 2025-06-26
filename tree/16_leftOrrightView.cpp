class Solution
{
public:
  void solve(Node *root, vector<int> &ans, int len)
  {
    if (root == nullptr)
    {
      return;
    }

    if (len == ans.size())
    {
      ans.push_back(root->data);
    }

    solve(root->left, ans, len + 1);
    solve(root->right, ans, len + 1);
  }
  vector<int> leftView(Node *root)
  {
    // code here
    vector<int> ans;
    if (root == nullptr)
    {
      return ans;
    }
    solve(root, ans, 0);
    return ans;
  }
};

class Solution
{
public:
  void solve(Node *root, vector<int> &ans, int len)
  {
    if (root == nullptr)
    {
      return;
    }

    if (len == ans.size())
    {
      ans.push_back(root->data);
    }

    solve(root->right, ans, len + 1);
    solve(root->left, ans, len + 1);
  }
  vector<int> rightView(Node *root)
  {
    // code here
    vector<int> ans;
    if (root == nullptr)
    {
      return ans;
    }
    solve(root, ans, 0);
    return ans;
  }
};