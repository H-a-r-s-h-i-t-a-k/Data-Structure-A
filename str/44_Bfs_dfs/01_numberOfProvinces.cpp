class Solution
{
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    vector<int> adj[n];

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (isConnected[i][j] == 1 && i != j)
        {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    vector<int> visited(n, 0);
    int count = 0;
    // vector<vector<int>>ans;
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        count++;
        // vector<int>component;

        ////

        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while (!q.empty())
        {
          int front = q.front();
          q.pop();

          // component.push_back(front);
          for (auto &neb : adj[front])
          {
            if (!visited[neb])
            {
              visited[neb] = 1;
              q.push(neb);
            }
          }

        } ////

        // ans.push_back(component);
      }
    }

    //    return ans.size();
    return count;
  }
};