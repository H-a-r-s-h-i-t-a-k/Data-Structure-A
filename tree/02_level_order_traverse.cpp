#include <iostream>
#include<queue>
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
void levelOrderTraversal(Node *root)
{
  
  queue<Node*> q;
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

Node *Buildtree(Node *root)
{
  printf("Enter the data: ");
  int data;
  scanf("%d", &data);

  if (data == -1)
  {
    return nullptr;
  }
  root = new Node(data);

  root->left = Buildtree(root->left);
  root->right = Buildtree(root->right);
  return root;
}
int main()
{
  Node *ans = nullptr;
  ans = Buildtree(ans);
  levelOrderTraversal(ans);
}