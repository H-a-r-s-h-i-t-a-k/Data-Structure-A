/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 235. Lowest Common Ancestor of a Binary Search Tree
//     Solved
//         Medium
//             Topics
//                 premium lock icon
//                     Companies
//                         Given a binary search
//                         tree(BST),
//     find the lowest common ancestor(LCA)
// node of two given nodes in the BST.

//     According to the definition of LCA on Wikipedia : “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants(where we allow a node to be a descendant of itself)
//         .” 
        
        
        
        class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == nullptr)
      return root;
    // right part
    if (root->val < p->val && root->val < q->val)
    {
      return lowestCommonAncestor(root->right, p, q);
    }
    else
    {
      if (root->val > p->val && root->val > q->val)
      {
        return lowestCommonAncestor(root->left, p, q);
      }
    }
    return root;
  }
};