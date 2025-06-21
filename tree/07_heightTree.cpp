int  solve(TreeNode* root){
  if(root==NULL) return 0;

 int left= solve(root->left);
 int right=solve(root->right);

 int ans=max(left,right)+1;
 return ans;
}
int maxDepth(TreeNode* root) {
 
  return solve(root);
 
}