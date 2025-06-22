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
  vector<vector<int>> vot(TreeNode *root)
  {

    // step1 initialise ds map for  mapping Horizontal distance wise node to level wise Nodes
    map<int, map<int, vector<int>>> nodes;
    // step2 initialise ds queue for level wise nodes to its horizontal distance , level numbering
    queue<pair<TreeNode *, pair<int, int>>> q;
    // step 3 make vector  and queue initialize base condition
    vector<vector<int>> result;

    if (root == nullptr)
    {
      return result;
    }
    q.push(make_pair(root, make_pair(0, 0)));

    // step 4 traverse normal case
    while (!q.empty())
    {
      pair<TreeNode *, pair<int, int>> temp = q.front();

      q.pop();
      TreeNode *frontNode = temp.first;
      int hd = temp.second.first;
      int level = temp.second.second;
      nodes[hd][level].push_back(frontNode->val);

      if (frontNode->left)
      {
        q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
      }
      if (frontNode->right)
      {
        q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
      }
      // step 5 store ans in vector

    } // while
    for (auto &i : nodes)
    {
      vector<int> ans;
      for (auto &j : i.second)
      {
        vector<int> &vec = j.second;
        sort(vec.begin(), vec.end());
        for (auto &k : j.second)
        {
          ans.push_back(k);
        }
      }
      result.push_back(ans);
    }
    return result;
  }

  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    return vot(root);
  }
};