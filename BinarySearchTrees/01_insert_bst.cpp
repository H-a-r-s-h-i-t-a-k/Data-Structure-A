class Solution
{
  TreeNode *solve(TreeNode *&root, int val)
  {
    if (root == NULL)
    {
      root = new TreeNode(val);

      return root;
    }
    if (val < root->val)
    {
      root->left = solve(root->left, val);
    }
    else
    {
      root->right = solve(root->right, val);
    }
    return root;
  }

public:
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    solve(root, val);
    return root;
  }
};

class Solution
{
  Node *solve(Node *&node, int key)
  {
    if (node == NULL)
    {
      node = new Node(key);
      return node;
    }
    if (key < node->data)
    {
      node->left = solve(node->left, key); // Insert into left subtree
    }
    else if (key > node->data)
    {
      node->right = solve(node->right, key); // Insert into right subtree
    }

    return node;
  }

public:
  Node *insert(Node *node, int key)
  {

    // Your code goes here

    return solve(node, key);
  }
};