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
  TreeNode *createNodeToParent(TreeNode *root, map<TreeNode *, TreeNode *> &nodeToparent, int target)
  {
    TreeNode *ans = nullptr;
    queue<TreeNode *> q;
    q.push(root);
    nodeToparent[root] = nullptr;
    while (!q.empty())
    {
      TreeNode *front = q.front();
      q.pop();

      if (front->val == target)
      {
        ans = front;
      }
      if (front->left)
      {
        q.push(front->left);
        nodeToparent[front->left] = front;
      }
      if (front->right)
      {
        q.push(front->right);
        nodeToparent[front->right] = front;
      }
    }
    return ans;
  }

  int solve(TreeNode *root, map<TreeNode *, TreeNode *> nodeToparent)
  {
    int ans = 0;
    map<TreeNode *, bool> visited;
    visited[root] = 1;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int flag = 0;
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        TreeNode *front = q.front();
        q.pop();

        if (front->left && !visited[front->left])
        {
          q.push(front->left);
          visited[front->left] = 1;
          flag = 1;
        }
        if (front->right && !visited[front->right])
        {
          q.push(front->right);
          visited[front->right] = 1;
          flag = 1;
        }
        if (nodeToparent[front] && !visited[nodeToparent[front]])
        {
          flag = 1;
          q.push(nodeToparent[front]);
          visited[nodeToparent[front]] = 1;
        }
      } // for
      if (flag == 1)
      {
        ans++;
      }
    } // while

    return ans;
  }

public:
  int amountOfTime(TreeNode *root, int start)
  {
    // code here
    // step1 create parent to node mapping
    int ans = 0;
    map<TreeNode *, TreeNode *> nodeToparent;

    // step2 find target node
    TreeNode *targetNode = createNodeToParent(root, nodeToparent, start);

    ans = solve(targetNode, nodeToparent);
    // step3 min time to burn tree
    return ans;
  }
};
