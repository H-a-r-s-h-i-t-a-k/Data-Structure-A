class Solution
{
public:
  bool isSafe(int newRow, int newCol, int n, vector<vector<int>> &maze, vector<vector<bool>> &visited)
  {
    if ((newRow >= 0 && newRow < n) && (newCol >= 0 && newCol < n) && (visited[newRow][newCol] != 1 && maze[newRow][newCol] == 1))
    {
      return 1;
    }
    else
      return 0;
  }
  void solve(int row, int col, int n, vector<vector<int>> &maze, vector<string> &ans, vector<vector<bool>> &visited, string path)
  {
    if (row == n - 1 && col == n - 1)
    {
      ans.push_back(path);
      return;
    }
    // start=00;
    // down=10
    // left=0-1
    // right=01
    // up=-10
    visited[row][col] = 1;
    if (isSafe(row + 1, col, n, maze, visited))
    {
      solve(row + 1, col, n, maze, ans, visited, path + "D");
    }
    if (isSafe(row, col - 1, n, maze, visited))
    {
      solve(row, col - 1, n, maze, ans, visited, path + "L");
    }
    if (isSafe(row, col + 1, n, maze, visited))
    {
      solve(row, col + 1, n, maze, ans, visited, path + "R");
    }
    if (isSafe(row - 1, col, n, maze, visited))
    {
      solve(row - 1, col, n, maze, ans, visited, path + "U");
    }
    visited[row][col] = 0;
  }
  vector<string> ratInMaze(vector<vector<int>> &maze)
  {
    // code here
    vector<string> ans;
    string path;
    int n = maze.size();
    if (maze[0][0] == 0)
      return ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    solve(0, 0, n, maze, ans, visited, path);
    return ans;
  }
