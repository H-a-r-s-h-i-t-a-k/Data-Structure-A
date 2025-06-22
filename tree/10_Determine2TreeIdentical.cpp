class Solution
{
public:
  // Function to check if two trees are identical.
  bool isIdentical(Node *r1, Node *r2)
  {
    Node *p = r1;
    Node *q = r2;
    // Your Code here
    if (p == NULL && q == NULL)
    {
      return true;
    }
    if (q == NULL && p != NULL)
    {
      return false;
    }
    if (q != NULL && p == NULL)
    {
      return false;
    }
    bool left = isIdentical(p->left, q->left);
    bool right = isIdentical(p->right, q->right);
    bool con = (p->data == q->data);

    if (left && right && con)
    {
      return true;
    }
    else
    {

      return false;
    }
  }
};