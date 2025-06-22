
class Solution
{
public:
  void leftTraverse(Node *root, vector<int> &result)
  {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
      return;
    }
    result.push_back(root->data);
    if (root->left)
      leftTraverse(root->left, result);
    else
      leftTraverse(root->right, result);
  }
  void leafTraverse(Node *root, vector<int> &result)
  {
    if (root == nullptr)
      return;
    if (!root->left && !root->right)
    {
      result.push_back(root->data);
      return;
    }

    leafTraverse(root->left, result);
    leafTraverse(root->right, result);
  }
  void rightTraverse(Node *root, vector<int> &result)
  {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
      return;
    }
    if (root->right)
      rightTraverse(root->right, result);
    else
      rightTraverse(root->left, result);
    result.push_back(root->data);
  }
  vector<int> boundaryTraversal(Node *root)
  {
    // code here
    vector<int> result;
    if (root == nullptr)
    {
      return result;
    }
    result.push_back(root->data);

    leftTraverse(root->left, result);

    leafTraverse(root->left, result);
    leafTraverse(root->right, result);

    rightTraverse(root->right, result);

    return result;
  }
};
