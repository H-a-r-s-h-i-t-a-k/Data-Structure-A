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
void preOrder(Node* root){
  if(root==NULL){
    return;
  }
  //nlr
  printf("%d",root->data);
  preOrder(root->left);
  preOrder(root->right);


}
void inOrder(Node* root){
  if(root==nullptr) return ;
  //lnr
  inOrder(root->left);
  printf("%d",root->data);
  inOrder(root->right);

}
void postOrder(Node* root){
  if(root==nullptr){
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  printf("%d",root->data);
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
  // levelOrderTraversal(ans);
  preOrder(ans);
  printf(" \n");
  inOrder(ans);
  printf(" \n");
  postOrder(ans);
  printf(" \n");
}