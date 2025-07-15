
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
void prepareAdj(unordered_map<int, list<int>> &adj, vector<vector<int>> &edges)
{
  for (auto &pr : edges)
  {
    int u = pr[0];
    int v = pr[1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans)
{
  ans.push_back(node);
  visited[node] = 1;
  for (auto &element : adj[node])
  {
    if (!visited[element])
    {
      dfs(element, adj, visited, ans);
    }
  }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
  unordered_map<int, bool> visited;
  unordered_map<int, list<int>> adj;
  vector<vector<int>> res;
  prepareAdj(adj, edges);
  // Write your code here
  for (int i = 0; i < V; i++)
  {
    vector<int> ans;
    if (!visited[i])
    {
      dfs(i, adj, visited, ans);
      res.push_back(ans);
    }
  }

  return res;
}