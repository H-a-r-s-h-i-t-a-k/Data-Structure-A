pair<int, int> univalue(BinaryTreeNode<int> *root)
{

  if (root == NULL)
  {

    return make_pair(-1, 0);
  }

  pair<int, int> ld = univalue(root->left);

  pair<int, int> rd = univalue(root->right);

  int tmp = root->data;

  int c = 0;

  int m = 0;

  if (root->data == ld.first)
  {

    c += root->left->data;

    m = max(m, root->left->data);
  }

  if (root->data == rd.first)
  {

    c += root->right->data;

    m = max(m, root->right->data);
  }

  root->data = m + 1;

  int maxuni = max(max(ld.second, rd.second), c + 1);

  return make_pair(tmp, maxuni);
}

int longestUnivaluePath(BinaryTreeNode<int> *root)
{

  return univalue(root).second - 1;
}