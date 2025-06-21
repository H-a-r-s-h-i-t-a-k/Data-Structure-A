#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};
Node *buildTreelot(Node *root)
{
  printf("\nEnter the data parant Element: ");
  int temp = 0;
  scanf("%d", &temp);
  if (temp == -1)
  {
    return NULL;
  }
  queue<Node *> q;
  root = new Node(temp);
  q.push(root);

  while (!q.empty())
  {
    Node *parent = q.front();
    q.pop();
    temp = 0;
    printf("\nEnter the left child :");
    scanf("%d", &temp);
    if (temp != -1)
    {
      parent->left = new Node(temp);
      q.push(parent->left);
    }
    temp = 0;
    printf("\nEnter the value of right child: ");
    scanf("%d", &temp);
    if (temp != -1)
    {
      parent->right = new Node(temp);
      q.push(parent->right);
    }
  }
  return root;
}
void preOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  // nlr
  printf("%d", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

int countLeaves(Node *root)
{
  // write code here
  if (root == NULL)
  {
    return 0;
  }
  queue<Node *> q;
  q.push(root);
  int c = 0;

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp->left == nullptr && temp->right == nullptr)
    {
      c++;
    }

    if (temp->left)
    {
      q.push(temp->left);
    }
    if (temp->right)
    {
      q.push(temp->right);
    }
  }

  return c;
}
void levelOrderTraversal(Node *root)
{

  queue<Node *> q;
  q.push(root);
  q.push(nullptr);

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp == nullptr)
    {

      printf("\n");
      if (!q.empty())
      {
        q.push(nullptr);
      }
    }
    else
    {
      printf("%d  ", temp->data);

      if (temp->left)
      {
        q.push(temp->left);
      }
      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}

int main()
{
  Node *ans = nullptr;
  ans = buildTreelot(ans);
  preOrder(ans);
  levelOrderTraversal(ans);
  printf("Count  leaf:  :%d",countLeaves(ans));
}