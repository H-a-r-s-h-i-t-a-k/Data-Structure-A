#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>

class Graph
{
  // void prepareAdj(vector<int> adj[], unordered_map<int, list<int>> &adjList)
  // {
  //   for (auto ele : adj)
  //   {
  //     int u = ele[0];
  //     int v = ele[1];
  //     adjList[u].push_back(v);
  //     adjList[v].push_back(u);
  //   }
  // }

  bool bfs(int node, vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, int> &parent)
  {

    queue<int> q;
    q.push(node);
    parent[node] = -1;
    visited[node] = 1;

    while (!q.empty())
    {
      int front = q.front();
      q.pop();

      for (auto &neb : adj[front])
      {
        if (visited[neb] && parent[front] != neb)
        {
          return true;//back edges
        }
        else if (!visited[neb])
        {
          q.push(neb);
          parent[neb] = front;
          visited[neb] = 1;
        }
      }
    }
    return false;
  }

public:
  bool detectCycle(int V, vector<int> adj[])
  {
    // Write your code here.
    // unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    // prepareAdj(adj, adjList);

    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        bool ans = bfs(i, adj, visited, parent);
        if (ans)
        {
          return true;
        }
      }
    }
    return false;
  }
};