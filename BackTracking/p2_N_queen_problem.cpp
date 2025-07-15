class Solution
{
public:
  void addans(vector<vector<int>> &board, vector<vector<string>> &sol, int n)
  {
    vector<string> temp;
    for (int r = 0; r < n; r++)
    {
      string row = "";
      for (int j = 0; j < n; j++)
      {
        if (board[r][j] == 1)
          row += "Q";
        else
          row += ".";
      }
      temp.push_back(row);
    }
    sol.push_back(temp);
  }

  bool isPossible(int i, int j, vector<vector<int>> &board, int n)
  {
    // Check left row
    for (int col = 0; col < j; col++)
    {
      if (board[i][col] == 1)
        return false;
    }

    // Check upper left diagonal
    for (int row = i, col = j; row >= 0 && col >= 0; row--, col--)
    {
      if (board[row][col] == 1)
        return false;
    }

    // Check lower left diagonal
    for (int row = i, col = j; row < n && col >= 0; row++, col--)
    {
      if (board[row][col] == 1)
        return false;
    }

    return true;
  }

  void solve(int col, vector<vector<int>> &board, vector<vector<string>> &sol, int n)
  {
    if (col == n)
    {
      addans(board, sol, n);
      return;
    }

    for (int row = 0; row < n; row++)
    {
      if (isPossible(row, col, board, n))
      {
        board[row][col] = 1;
        solve(col + 1, board, sol, n);
        board[row][col] = 0; // backtrack
      }
    }
  }

  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> sol;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, board, sol, n);
    return sol;
  }
};
