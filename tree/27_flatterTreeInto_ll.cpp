TreeNode // User function Template for C++

    class Solution
{
public:
  void flatten(Node *root)
  {
    // code here
    Node *prev = nullptr;
    Node *curr = root;
    while (curr != nullptr)
    {
      if (curr->left)
      {
        prev = curr->left;
        while (prev->right != NULL)
        {
          prev = prev->right;
        }
        prev->right = curr->right;
        curr->right = curr->left;
        curr->left = nullptr;
      }
      curr = curr->right;
    }
  }
};