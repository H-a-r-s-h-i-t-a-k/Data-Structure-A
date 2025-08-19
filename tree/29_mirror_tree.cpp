class Solution
{
public:
  void mirror(Node *node)
  {
    if (node == nullptr)
    {
      return;
    }
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    if (node->left)
    {
      mirror(node->left);
    }
    if (node->right)
    {
      mirror(node->right);
    }
    // code here
  }
};