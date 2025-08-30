// vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
//     vector<int> ans;

//     vector<int>visited(n+1,0);

//             queue<int>q;
//             q.push(0);
//             visited[0]=1;
//             while(!q.empty()){
//                 int front=q.front();
//             ans.push_back(front);
//                 q.pop();

//                 for(auto& neb:adj[front]){
//                     if(!visited[neb]){
//                         q.push(neb);

//                         visited[neb]=1;
//                     }
//                 }
//             }

//     // Write your code here.

// return ans;

// }

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{

  // Step 1: Create a queue

  queue<int> q;

  // Step 2: Choose a source node (assuming 0 here)

  int src = 0;

  q.push(src);

  // Step 3: Keep track of visited nodes

  unordered_map<int, bool> visited;

  visited[src] = true;

  // Step 4: Perform BFS traversal

  vector<int> result;

  while (!q.empty())
  {

    int frontNode = q.front();

    q.pop();

    result.push_back(frontNode);

    // Insert neighbors

    for (auto n : adj[frontNode])
    {

      if (!visited[n])
      {

        q.push(n);

        visited[n] = true;
      }
    }
  }

  return result;
}