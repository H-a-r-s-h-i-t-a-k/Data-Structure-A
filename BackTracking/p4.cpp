





// bfs
////////////////////////////////////////////////

class Solution
{
public:
  set<vector<int>> visited;
  set<vector<int>> block;
  int row[4] = {-1, 0, 1, 0};
  int col[4] = {0, -1, 0, 1};
  bool solve(int bl,vector<int> &start, vector<int> &end)
  {
    int n = block.size() * block.size();
    int cnt = 0;
    int i = start[0], j = start[1];
    queue<vector<int>> q;
    visited.clear();
    visited.insert(start);
    q.push(start);

    while (!q.empty())
    {
      vector<int> item = q.front();
      q.pop();
      int r = item[0], c = item[1];
      // target reached
      if (r == end[0] && c == end[1])
      {
        return true;
      }
      // limit blocks
      if (cnt++ > n)
        return true;

      for (int i = 0; i < 4; i++)
      {
        int nr = r + row[i];
        int nc = c + col[i];

        if (nr >= 0 && nc >= 0 && nr < 1e6 && nc < 1e6)
        {
          vector<int> next = {nr, nc};
          if (!block.count(next) && !visited.count(next))
          {
            visited.insert(next);
            q.push(next);
          }
        }
      }
    }
    return false;
  }
  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
  {
    for (auto &item : blocked)
    {
      block.insert(item);
    }
    return solve(source, target) && solve(target, source);
  }
};


///////////////////dfs

class Solution
{
public:
  set<pair<int, int>> blockedSet;
  set<pair<int, int>> visited;
  const int BOUND = 1e6;
  int MAX_VISITS;
  int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  bool dfs(int x, int y, int tx, int ty, int &count)
  {
    if (x == tx && y == ty)
      return true;
    if (++count > MAX_VISITS)
      return true;

    visited.insert({x, y});

    for (int d = 0; d < 4; ++d)
    {
      int nx = x + DIR[d][0];
      int ny = y + DIR[d][1];
      pair<int, int> next = {nx, ny};

      if (nx >= 0 && ny >= 0 && nx < BOUND && ny < BOUND &&
          !blockedSet.count(next) && !visited.count(next))
      {
        if (dfs(nx, ny, tx, ty, count))
          return true;
      }
    }
    return false;
  }

  bool check(vector<int> &start, vector<int> &end)
  {
    visited.clear();
    int count = 0;
    return dfs(start[0], start[1], end[0], end[1], count);
  }

  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
  {
    for (auto &b : blocked)
    {
      blockedSet.insert({b[0], b[1]});
    }

    MAX_VISITS = blocked.size() * (blocked.size() - 1) / 2;
    return check(source, target) && check(target, source);
  }
};