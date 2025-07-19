class Solution
{
public:
  bool ispossible(int row, int col, vector<vector<char>> &board, char val)
  {
    int n = board[0].size();
    for (int i = 0; i < n; i++)
    {
      // row check
      if (board[row][i] == val)
      {
        return false;
      }
      if (board[i][col] == val)
      {
        return false;
      }
      if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
      {
        return false;
      }
    }
    return true;
  }
  bool solve(vector<vector<char>> &board)
  {
    int n = board.size();
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < n; col++)
      {
        if (board[row][col] == '.')
        {
          for (char i = '1'; i <= '9'; i++)
          {
            if (ispossible(row, col, board, i))
            {
              board[row][col] = i;
              if (solve(board))
              {
                return true;
              }

              board[row][col] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  void solveSudoku(vector<vector<char>> &board)
  {
    int n = board[0].size();
    solve(board);
  }
};