#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;
bool cyclebfs(int i, vector<int> &visited, unordered_map<int, int> &parent, unordered_map<int, list<int>> &adj)
{
  queue<int> q;
  q.push(i);
  visited[i] = 1;
  parent[i] = -1;

  while (!q.empty())
  {
    int front = q.front();
    q.pop();

    for (auto &neb : adj[front])
    {
      if (visited[neb] == 1 && neb != parent[front])
      {
        return true;
      }
      else if (!visited[neb])
      {
        visited[neb] = 1;
        parent[neb] = front;
        q.push(neb);
      }
    }
  }
  return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
  unordered_map<int, list<int>> adj;
  vector<int> visited(n + 1, 0);

  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  unordered_map<int, int> parent;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      bool ans = cyclebfs(i, visited, parent, adj);
      if (ans)
      {
        return "Yes";
      }
    }
  }

  return "No";
  // Write your code here.
}
