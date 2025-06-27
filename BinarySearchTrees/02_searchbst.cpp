class Solution
{
public:
  TreeNode *searchBST(TreeNode *root, int val)
  {
    if (root == nullptr)
      return nullptr;
    if (root->val == val)
    {
      return root;
    }
    if (root->val < val)
      return searchBST(root->right, val);

    return searchBST(root->left, val);
  }
};

bool search(Node *root, int x)
{
  if (root == NULL)
    return false;
  if (root->data == x)
  {
    return true;
  }
  if (root->data < x)
  {
    return search(root->right, x);
  }
  else
    return search(root->left, x);
}