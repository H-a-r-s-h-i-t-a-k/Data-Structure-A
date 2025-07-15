#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
//////////////////////////dfs//////////////////////////////////
void prepareAdj(vector<vector<int>> &edges, unordered_map<int, list<int>> &adj)
{
  for (auto &item : edges)
  {
    int u = item[0];
    int v = item[1];

    adj[u].push_back(v);
    // adj[v].push_back(u);
  }
}

bool dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvis)
{
  visited[node] = 1;
  dfsvis[node] = 1;
  for (auto &child : adj[node])
  {
    if (!visited[child])
    {
      bool cyclepresent = dfs(child, adj, visited, dfsvis);
      if (cyclepresent)
        return true;
    }
    else if (dfsvis[child])
    {
      return true;
    }
  }
  dfsvis[node] = 0;
  return false;
}

bool isCyclic(vector<vector<int>> &edges, int v, int e)

{
  unordered_map<int, list<int>> adj;
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsvis;
  prepareAdj(edges, adj);

  bool ans = false;
  // Write your code here

  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
    {
      ans = dfs(i, adj, visited, dfsvis);
      if (ans)
      {
        return true;
      }
    }
  }

  return false;
}