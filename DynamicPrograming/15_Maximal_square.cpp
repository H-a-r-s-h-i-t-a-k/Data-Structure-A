class Solution
{
public:
  int solveR(vector<vector<char>> &matrix, int i, int j, int &maxnum)
  {
    if (i >= matrix.size() || j >= matrix[0].size())
    {
      return 0;
    }
    int ans = 0;
    int left = solveR(matrix, i, j + 1, maxnum);
    int down = solveR(matrix, i + 1, j, maxnum);
    int daigonal = solveR(matrix, i + 1, j + 1, maxnum);
    if (matrix[i][j] == '1')
    {
      ans = 1 + min(left, min(down, daigonal));

      maxnum = max(maxnum, ans);
      return ans;
    }
    else
      return 0;
  }

  int solveM(vector<vector<char>> &matrix, int i, int j, int &maxnum, vector<vector<int>> &dp)
  {
    if (i >= matrix.size() || j >= matrix[0].size())
    {
      return 0;
    }
    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }

    int ans = 0;
    int left = solveM(matrix, i, j + 1, maxnum, dp);
    int down = solveM(matrix, i + 1, j, maxnum, dp);
    int diagonal = solveM(matrix, i + 1, j + 1, maxnum, dp);

    if (matrix[i][j] == '1')
    {
      ans = 1 + min(left, min(down, diagonal));
      maxnum = max(ans, maxnum);

      dp[i][j] = ans;
    }
    else
    {
      dp[i][j] = 0;
    }
    return dp[i][j];
  }

  void solveT(vector<vector<char>> &matrix, int &maxnum)
  {
    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    for (int i = row - 1; i >= 0; i--)
    {
      int ans = 0;
      for (int j = col - 1; j >= 0; j--)
      {
        int left = dp[i][j + 1];
        int down = dp[i + 1][j];
        int diagonal = dp[i + 1][j + 1];
        if (matrix[i][j] == '1')
        {
          ans = 1 + min({left, down, diagonal});
          maxnum = max(maxnum, ans);
          dp[i][j] = ans;
        }
        else
        {
          dp[i][j] = 0;
        }
      }
    }
  }

  void solveS(vector<vector<char>> &matrix, int &maxnum)
  {
    int col = matrix[0].size();
    int row = matrix.size();
    vector<int> prev(col + 1, 0);
    vector<int> curr(col + 1, 0);

    for (int i = row - 1; i >= 0; i--)
    {
      for (int j = col - 1; j >= 0; j--)
      {
        int left = prev[j + 1];
        int down = curr[j];
        int diagonal = curr[j + 1];

        int ans = 0;
        if (matrix[i][j] == '1')
        {
          ans = 1 + min({left, down, diagonal});
          maxnum = max(ans, maxnum);
          curr[j] = ans;
        }
        else
        {
          curr[j] = 0;
        }
      }
      prev = curr;
    }
  }

  int maximalSquare(vector<vector<char>> &matrix)
  {
    // int maxnum=0;
    //  solveR(matrix,0,0,maxnum);
    // return maxnum*maxnum;

    // m2 memorization
    //  int maxnum=0;
    // int col=matrix[0].size();
    // int row=matrix.size();
    // vector<vector<int>>dp(row,vector<int>(col+1,-1));
    // solveM(matrix,0,0,maxnum,dp);
    // return maxnum*maxnum;

    // m3 Tabulation
    int maxnum = 0;
    solveS(matrix, maxnum);
    return maxnum * maxnum;
  }
};