
/////////////////////////////////////////////////////////////////bfs///

class Solution
{
public:
  vector<int> topoSort(int V, vector<vector<int>> &edges)
  {
    // code here
    unordered_map<int, list<int>> adj;
    for (auto &item : edges)
    {
      int u = item[0];
      int v = item[1];

      adj[u].push_back(v);
    }

    // int n=edges.size();
    vector<int> indegree(V, 0);
    for (auto &ele : adj)
    {
      for (auto &el : ele.second)
      {
        indegree[el]++;
      }
    }
    int root;
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int front = q.front();
      q.pop();
      ans.push_back(front);

      for (auto &ch : adj[front])
      {
        indegree[ch]--;
        if (indegree[ch] == 0)
        {
          q.push(ch);
        }
      }
    }

    return ans;
  }
};

///////////////////////////dfs///////////////////////////////