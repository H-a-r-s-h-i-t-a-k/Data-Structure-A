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

optttttttttttt time only not space

    class Solution
{
public:
  bool rowUsed[9][9] = {};
  bool colUsed[9][9] = {};
  bool boxUsed[9][9] = {};

  bool solve(vector<vector<char>> &board)
  {
    for (int row = 0; row < 9; row++)
    {
      for (int col = 0; col < 9; col++)
      {
        if (board[row][col] == '.')
        {
          for (int num = 0; num < 9; num++)
          {
            int boxIdx = (row / 3) * 3 + (col / 3);
            if (!rowUsed[row][num] && !colUsed[col][num] && !boxUsed[boxIdx][num])
            {
              board[row][col] = num + '1';
              rowUsed[row][num] = colUsed[col][num] = boxUsed[boxIdx][num] = true;

              if (solve(board))
                return true;

              // Backtrack
              board[row][col] = '.';
              rowUsed[row][num] = colUsed[col][num] = boxUsed[boxIdx][num] = false;
            }
          }
          return false; // No valid number can be placed here
        }
      }
    }
    return true; // Solved
  }

  void solveSudoku(vector<vector<char>> &board)
  {
    // Pre-fill the tracking arrays
    for (int row = 0; row < 9; row++)
    {
      for (int col = 0; col < 9; col++)
      {
        if (board[row][col] != '.')
        {
          int num = board[row][col] - '1';
          int boxIdx = (row / 3) * 3 + (col / 3);
          rowUsed[row][num] = true;
          colUsed[col][num] = true;
          boxUsed[boxIdx][num] = true;
        }
      }
    }
    solve(board);
  }
};
