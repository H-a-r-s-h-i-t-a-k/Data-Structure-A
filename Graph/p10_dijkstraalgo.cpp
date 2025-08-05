// User Function Template
// class Solution {
//   public:
//     vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
//         // Code here

//     }
// };

class Solution
{
public:
  vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
  {
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];

      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(V);
    for (int i = 0; i < V; i++)
    {
      dist[i] = INT_MAX;
    }
    set<pair<int, int>> st;
    st.insert(make_pair(0, src));
    dist[src] = 0;

    while (st.size() > 0)
    {
      auto &front = *(st.begin());
      int distance = front.first;
      int node = front.second;

      st.erase(st.begin());
      for (auto &neb : adj[node])
      {
        if (distance + neb.second < dist[neb.first])
        {
          auto res = st.find(make_pair(dist[neb.first], neb.first));
          if (res != st.end())
          {
            st.erase(make_pair(dist[neb.first], neb.first));
          }

          dist[neb.first] = distance + neb.second;
          st.insert(make_pair(dist[neb.first], neb.first));
        }
      }
    }
    return dist;
  }
};