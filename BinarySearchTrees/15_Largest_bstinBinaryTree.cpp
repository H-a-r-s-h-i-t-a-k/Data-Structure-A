/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Info
{
public:
  int maxi, mini, size;
  bool isBst;
};
class Solution
{
  Info solvebst(Node *root, int &ans)
  {
    if (root == nullptr)
    {
      return {INT_MIN, INT_MAX, 0, true};
    }

    Info left = solvebst(root->left, ans);
    Info right = solvebst(root->right, ans);

    Info curr;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);
    curr.size = left.size + right.size + 1;

    bool cond = root->data > left.maxi && root->data < right.mini;

    if (left.isBst && right.isBst && cond)
    {
      curr.isBst = true;
    }
    else
    {
      curr.isBst = false;
    }

    if (curr.isBst)
    {
      ans = max(ans, curr.size);
    }
    return curr;
  }

public:
  /*You are required to complete this method */
  // Return the size of the largest sub-tree which is also a BST
  int largestBst(Node *root)
  {
    // Your code here

    int count = 0;
    Info info = solvebst(root, count);
    return count;
  }
};