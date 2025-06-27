/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution
{
public:
  Node *rightMost(Node *node)
  {
    while (node->right != nullptr)
    {
      node = node->right;
    }
    return node;
  }

  Node *leftMost(Node *node)
  {
    while (node->left != nullptr)
    {
      node = node->left;
    }
    return node;
  }

  // Return predecessor and successor as a vector<Node*>
  vector<Node *> findPreSuc(Node *root, int key)
  {
    Node *pre = nullptr;
    Node *suc = nullptr;
    Node *curr = root;

    while (curr != nullptr)
    {
      if (curr->data < key)
      {
        pre = curr;
        curr = curr->right;
      }
      else if (curr->data > key)
      {
        suc = curr;
        curr = curr->left;
      }
      else
      {
        if (curr->left != nullptr)
          pre = rightMost(curr->left);
        if (curr->right != nullptr)
          suc = leftMost(curr->right);
        break;
      }
    }

    return {pre, suc};
  }
};
