// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution
{
  void countNodeTree(Node *tree, int &cnt)
  {
    if (tree == nullptr)
      return;
    countNodeTree(tree->left, cnt);
    cnt++;
    countNodeTree(tree->right, cnt);
  }

  bool iscbt(Node *tree, int i, int &countNode)
  {
    if (tree == nullptr)
    {
      return true;
    }
    if (i >= countNode)
    {
      return false;
    }
    bool left = iscbt(tree->left, i * 2 + 1, countNode);
    bool right = iscbt(tree->right, i * 2 + 2, countNode);
    return left && right;
  }

  bool ismaxorder(Node *tree)
  {
    if (tree->left == nullptr && tree->right == nullptr)
    {
      return true;
    }
    if (tree->right == nullptr)
    {
      return (tree->left->data < tree->data);
    }
    else
    {
      return tree->data > tree->left->data && tree->data > tree->right->data && ismaxorder(tree->left) && ismaxorder(tree->right);
    }
  }

public:
  bool isHeap(Node *tree)
  {
    int countNode = 0;
    countNodeTree(tree, countNode);
    // code here
    return (iscbt(tree, 0, countNode) && ismaxorder(tree));
  }
};
