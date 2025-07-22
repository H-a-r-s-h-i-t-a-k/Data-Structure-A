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

Node* buildTreelot(Node* root){
  printf("\nEnter the data parant Element: ");
  int temp=0;
  scanf("%d",&temp);
  if(temp==-1){
    return NULL;
  }
  queue<Node*> q;
   root=new Node(temp);
   q.push(root);

   while(!q.empty()){
    Node* parent=q.front();
    q.pop();
    temp=0;
    printf("\nEnter the left child :");
    scanf("%d",&temp);
    if(temp!=-1){
      parent->left=new Node(temp);
      q.push(parent->left);
    }
    temp=0;
    printf("\nEnter the value of right child: ");
    scanf("%d",&temp);
    if(temp!=-1){
      parent->right=new Node(temp);
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

int main()
{
  Node *ans = nullptr;
  ans = buildTreelot(ans);
  preOrder(ans);
}