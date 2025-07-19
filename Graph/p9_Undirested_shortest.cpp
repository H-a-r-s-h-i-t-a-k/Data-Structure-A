




///////////////////////////////////////////////dfs///////////////////////


////////////////////////bfs//////////////////////

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

  // Write your code here
  unordered_map<int, list<int>> adj;
  unordered_map<int, bool> visited;
  unordered_map<int, int> parent;

  for (auto &node : edges)
  {
    int u = node.first;
    int v = node.second;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  visited[s] = 1;
  parent[s] = -1;
  q.push(s);

  while (!q.empty())
  {
    int front = q.front();
    q.pop();

    for (auto &neb : adj[front])
    {

      if (!visited[neb])
      {
        visited[neb] = 1;
        parent[neb] = front;
        q.push(neb);
      }
      if (neb == t)
      {
        break;
      }
    }
  }

  vector<int> ans;
  ans.push_back(t);
  int curr = t;
  while (curr != s)
  {
    curr = parent[curr];
    ans.push_back(curr);
  }
  reverse(ans.begin(), ans.end());

  return ans;
}