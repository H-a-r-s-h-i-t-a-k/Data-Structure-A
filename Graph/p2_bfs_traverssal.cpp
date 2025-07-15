// Problem statement
//         Given an adjacency list representation of a directed graph with ‘n’ vertices and ‘m’ edges.Your task is to return a list consisting of Breadth -
//     First Traversal(BFS)
// starting from vertex 0.

//     In this traversal,
//     one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'.The BFS traversal should include all nodes directly or indirectly connected to vertex 0.

//                                                                                                                                                Note : The traversal should proceed from left to right according to the input adjacency list.

//                                                                                                                                                       Example : Adjacency list:
// {
//   {1, 2, 3}, {4}, {5}, {}, {}, {}
// }

// The interpretation of this adjacency list is as follows : Vertex 0 has directed edges towards vertices 1, 2, and 3. Vertex 1 has a directed edge towards vertex 4. Vertex 2 has a directed edge towards vertex 5. Vertices 3, 4, and 5 have no outgoing edges.

//                                                                                                                                                                                                                                      We can also see this in the diagram below.

//                                                                                                                                                                                                                                      BFS traversal : 0 1 2 3 4 5

#include <iostream>
                                                                                                                                                                                                                                     using namespace std;
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>

void bfs(int node, vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans)
{
  queue<int> q;
  q.push(node);
  visited[node] = 1;
  while (!q.empty())
  {

    int front = q.front();
    q.pop();
    ans.push_back(front);
    for (auto &element : adj[front])
    {
      if (!visited[element])
      {
        q.push(element);
        visited[element] = 1;
      }
    }
  }
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
  // Write your code here.
  // unordered_map<int,list<int>> adj;
  unordered_map<int, bool> visited;
  vector<int> ans;
  // for(int i=0;i<n;i++){
  if (!visited[0])
  {
    bfs(0, adj, visited, ans);
  }
  // }

  return ans;
}