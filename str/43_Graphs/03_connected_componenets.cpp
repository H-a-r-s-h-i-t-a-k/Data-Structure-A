
class Solution
{
public:
  void bfs(int i, vector<int> &visited, unordered_map<int, set<int>> &adj, vector<int> &component)
  {

    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
      int front = q.front();
      q.pop();
      component.push_back(front);
      visited[front] = 1;

      for (auto &neb : adj[front])
      {
        if (!visited[neb])
        {
          q.push(neb);
          visited[neb] = 1;
        }
      }
    }
  }

  vector<vector<int>> getComponents(int V, vector<vector<int>> &edges)
  {
    unordered_map<int, set<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[u].insert(v);
      adj[v].insert(u);
    }
    vector<vector<int>> ans;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        vector<int> component;
        bfs(i, visited, adj, component);
        ans.push_back(component);
      }
    }

    return ans;
    // code here
  }
};