class Solution
{
public:
  vector<int> solve(Node *root)
  {
    vector<int> result;
    if (root == nullptr)
    {
      return result;
    }
    queue<Node *> q;
    q.push(root);
    bool left_right = true;

    while (!q.empty())
    {

      int size = q.size();
      vector<int> ans(size, 0);

      for (int i = 0; i < size; i++)
      {
        Node *temp = q.front();
        q.pop();

        int index = left_right ? i : size - i - 1;
        ans[index] = temp->data;

        if (temp->left)
        {
          q.push(temp->left);
        }
        if (temp->right)
        {
          q.push(temp->right);
        }
      }

      for (auto num : ans)
      {
        result.push_back(num);
      }
      left_right = !left_right;
    }

    return result;
  }

  // Function to store the zig zag order traversal of tree in a list.
  vector<int> zigZagTraversal(Node *root)
  {
    // Code here

    return solve(root);
  }
};

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
  vector<vector<int>> solve(TreeNode *root)
  {
    vector<vector<int>> result;
    if (root == nullptr)
    {
      return result;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool left_right = true;

    while (!q.empty())
    {

      int size = q.size();
      vector<int> ans(size, 0);

      for (int i = 0; i < size; i++)
      {
        TreeNode *temp = q.front();
        q.pop();

        int index = left_right ? i : size - i - 1;
        ans[index] = temp->val;

        if (temp->left)
        {
          q.push(temp->left);
        }
        if (temp->right)
        {
          q.push(temp->right);
        }
      }

      result.push_back(ans);
      left_right = !left_right;
    }
    return result;
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    return solve(root);
  }
};