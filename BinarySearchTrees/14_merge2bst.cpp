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

  void inorderTovector(TreeNode *root, vector<int> &arr)
  {
    if (root == nullptr)
    {
      return;
    }
    inorderTovector(root->left, arr);
    arr.push_back(root->val);
    inorderTovector(root->right, arr);
  }

  void merge2vector(vector<int> &first, vector<int> &second, vector<int> &merge)
  {
    int i = 0, j = 0;
    int mergeNo = first.size() + second.size() + 1;
    int k = 0;
    while (i < first.size() && j < second.size())
    {
      if (first[i] < second[j])
      {
        merge[k++] = first[i++];
      }
      else
      {
        merge[k++] = second[j++];
      }
    }
    while (i < first.size())
    {
      merge[k++] = first[i++];
    }
    while (j < second.size())
    {
      merge[k++] = second[j++];
    }
  }

  TreeNode *inorderTobst(vector<int> &merge, int s, int e)
  {
    if (s > e)
    {
      return nullptr;
    }
    int mid = ((e - s) / 2) + s;
    TreeNode *newNode = new TreeNode(merge[mid]);
    newNode->left = inorderTobst(merge, s, mid - 1);
    newNode->right = inorderTobst(merge, mid + 1, e);
    return newNode;
  }

public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
  {
    vector<int> first;
    vector<int> second;
    inorderTovector(root1, first);
    inorderTovector(root2, second);

    int mergeNo = first.size() + second.size();
    vector<int> merge(mergeNo);
    merge2vector(first, second, merge);
    TreeNode *ansroot;
    ansroot = inorderTobst(merge, 0, mergeNo - 1);
    return ansroot;
  }
};