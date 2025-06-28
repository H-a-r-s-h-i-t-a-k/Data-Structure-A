
class Solution
{
  void inorderTovector(Node *&root, vector<int> &inorder)
  {
    if (root == nullptr)
      return;
    inorderTovector(root->left, inorder);
    inorder.push_back(root->data);
    inorderTovector(root->right, inorder);
  }

public:
  Node *flattenBST(Node *root)
  {
    // code here
    vector<int> inorder;
    if (root == nullptr)
      return root;

    inorderTovector(root, inorder);

    Node *rootNew = new Node(inorder[0]);
    Node *curr = rootNew;
    int n = inorder.size();
    for (int i = 1; i < n; i++)
    {
      Node *temp = new Node(inorder[i]);
      curr->right = temp;
      curr->left = nullptr;
      curr = curr->right;
    }

    curr->left = nullptr;
    curr->right = nullptr;

    return rootNew;
  }
};
