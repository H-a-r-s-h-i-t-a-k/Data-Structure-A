

#include <iostream>
#include <vector>

void dfs(int i, vector<bool> &visited, vector<int> adj[], vector<int> &component)
{
  visited[i] = true;
  component.push_back(i);

  for (auto &neb : adj[i])
  {
    if (!visited[neb])
    {
      // visited[i]=true;
      // component.push_back(neb);
      dfs(neb, visited, adj, component);
    }
  }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
  vector<int> adj[V];

  // unordered_map<int,list<int>>adj;
  for (int i = 0; i < E; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> ans;
  vector<bool> visited(V, 0);
  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      vector<int> component;
      dfs(i, visited, adj, component);
      ans.push_back(component);
    }
  }
  return ans;
  // Write your code here
}