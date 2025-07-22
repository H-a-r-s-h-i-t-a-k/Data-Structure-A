
optimize
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */

    /// @brief //////////preeeeeeeeeeee//////////////////////////
    class Solution
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    TreeNode *curr = root;
  
    while (curr != nullptr)
    {
      if (curr->left == nullptr)
      {
        ans.push_back(curr->val);
        curr = curr->right;
      }
      else
      {
        // find predeccessor
        TreeNode *pre = curr->left;
        while (pre->right != nullptr && pre->right != curr)
        {
          pre = pre->right;
        }
        if (pre->right == nullptr)
        {
          pre->right = curr;
          ans.push_back(curr->val);
          curr = curr->left;
        }
        else
        {
          pre->right = nullptr;
          curr = curr->right;
        }
      }
    }
    return ans;
  }
};

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
/////////////////////inorder ///////////////////////////////////////////////////

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    TreeNode *curr = root;

    while (curr != nullptr)
    {
      if (curr->left == nullptr)
      {
        ans.push_back(curr->val);
        curr = curr->right;
      }
      else
      {
        // find predeccessor
        TreeNode *pre = curr->left;
        while (pre->right != nullptr && pre->right != curr)
        {
          pre = pre->right;
        }
        if (pre->right == nullptr)
        {
          pre->right = curr;
          curr = curr->left;
        }
        else
        {
          pre->right = nullptr;
          ans.push_back(curr->val);
          curr = curr->right;
        }
      }
    }
    return ans;
  }
};
void inOrder(Node* root){
  if(root==nullptr) return ;
  //lnr
  inOrder(root->left);
  printf("%d",root->data);
  inOrder(root->right);

}///////////////////////////////////////////////////////////////////////////////post/////////////////////////////////////////


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