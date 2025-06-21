#include<iostream>

class Node{
  public:

  int data;
  Node* left;
  Node* right;

  Node(int data){
   this->data=data;left=nullptr;right=nullptr;

  }
};

Node* Buildtree(Node* root){
printf("Enter the data: ");
int data;
scanf("%d",&data);

if(data==-1){
  return nullptr;
}
root=new Node(data);

root->left=Buildtree(root->left);
root->right=Buildtree(root->right);
return root;

}
int  main(){
  Node* ans=nullptr;
  ans=Buildtree(ans);

}