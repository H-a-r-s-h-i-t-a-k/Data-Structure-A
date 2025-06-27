class Solution
{
  Node *minbst(Node *root)
  {
    Node *temp = root;
    while (temp->left != nullptr)
    {
      temp = temp->left;
    }
    return temp;
  }

public:
  // Function to delete a node from BST.
  Node *deleteNode(Node *root, int X)
  {
    // your code goes here
    if (root == nullptr)
      return root;
    if (root->data < X)
    {
      root->right = deleteNode(root->right, X);
    }
    else if (root->data > X)
    {
      root->left = deleteNode(root->left, X);
    }
    // if(root->data==X){
    else
    {
      // 0child
      if (root->left == nullptr && root->right == nullptr)
      {
        delete root;

        return nullptr;
      }
      // 1child

      // left
      else if (root->left != nullptr && root->right == nullptr)
      {
        Node *temp = root->left;
        delete root;
        return temp;
      }
      // right
      else if (root->left == nullptr && root->right != nullptr)
      {
        Node *temp = root->right;
        delete root;
        return temp;
      }
      // 2 child;
      else
      { //  if(root->left!=nullptr&& root->right!=nullptr){
        int mini = minbst(root->right)->data;

        // replace data
        root->data = mini;
        // delete right sub tree min
        root->right = deleteNode(root->right, mini);
      }
      // 0 child
    }
    return root;
  }
};