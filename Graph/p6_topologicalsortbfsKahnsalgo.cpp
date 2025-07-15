////////////////////////dfs/////////////////////
#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

void topo(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &stk)
{
  visited[node] = 1;
  for (auto &n : adj[node])
  {
    if (!visited[n])
    {
      topo(n, adj, visited, stk);
    }
  }
  stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
  // Write your code here!
  unordered_map<int, list<int>> adj;

  for (auto &ele : graph)
  {
    int u = ele[0];
    int v = ele[1];
    adj[u].push_back(v);
  }

  unordered_map<int, bool> visited;

  vector<int> ans;
  stack<int> stk;

  for (int i = 0; i < nodes; i++)
  {
    if (!visited[i])
    {
      topo(i, adj, visited, stk);
    }
  }

  while (!stk.empty())
  {
    ans.push_back(stk.top());
    stk.pop();
  }

  return ans;
}
