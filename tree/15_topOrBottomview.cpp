/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
  // Function to return a list of nodes visible from the top view
  // from left to right in Binary Tree.
  vector<int> topView(Node *root)
  {
    // code here
    vector<int> ans;
    if (root == nullptr)
    {
      return ans;
    }
    map<int, int> mp;
    queue<pair<int, Node *>> q;
    q.push(make_pair(0, root));

    while (!q.empty())
    {
      pair<int, Node *> temp = q.front();
      q.pop();
      Node *frontNode = temp.second;
      int hd = temp.first;
      if (mp.find(hd) == mp.end())
      {
        mp[hd] = frontNode->data;
      }

      if (frontNode->left)
      {
        q.push(make_pair(hd - 1, frontNode->left));
      }
      if (frontNode->right)
      {
        q.push(make_pair(hd + 1, frontNode->right));
      }
    }

    for (auto ele : mp)
    {
      ans.push_back(ele.second);
    }
    return ans;
  }
};

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
  vector<int> bottomView(Node *root)
  {
    // Your Code Here
    vector<int> ans;
    map<int, int> mp;
    queue<pair<int, Node *>> q;

    if (root == nullptr)
    {
      return ans;
    }
    q.push(make_pair(0, root));

    while (!q.empty())
    {
      pair<int, Node *> temp = q.front();
      q.pop();
      Node *frontNode = temp.second;
      int hd = temp.first;
      // if(mp.find(hd)==mp.end()){
      //     mp[hd]=front->data;
      // }

      mp[hd] = frontNode->data;
      if (frontNode->left)
      {
        q.push(make_pair(hd - 1, frontNode->left));
      }
      if (frontNode->right)
      {
        q.push(make_pair(hd + 1, frontNode->right));
      }

    } // while

    for (auto &ele : mp)
    {
      ans.push_back(ele.second);
    }
    return ans;
  }
};
