class Solution
{
  void inorderTovector(Node *&root, vector<int> &inorder)
  {
    if (root == nullptr)
    {
      return;
    }
    inorderTovector(root->left, inorder);
    inorder.push_back(root->data);
    inorderTovector(root->right, inorder);
  }
  Node *inorderTobst(vector<int> &inorder, int s, int e)
  {
    if (s > e)
    {
      return nullptr;
    }
    int mid = (e - s) / 2 + s;

    Node *newRoot = new Node(inorder[mid]);
    newRoot->left = inorderTobst(inorder, s, mid - 1);
    newRoot->right = inorderTobst(inorder, mid + 1, e);

    return newRoot;
  }

public:
  Node *balanceBST(Node *root)
  {
    // Code here
    vector<int> inorder;
    inorderTovector(root, inorder);
    int n = inorder.size();
    root = inorderTobst(inorder, 0, n - 1);
    return root;
  }
};
