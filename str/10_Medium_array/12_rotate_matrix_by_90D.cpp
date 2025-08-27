
class Solution
{
public:
  void swap(int &a, int &b)
  {
    int temp = a;
    a = b;
    b = temp;
  }
  void reverse(vector<int> &arr)
  {
    int s = 0;
    int e = arr.size() - 1;
    while (s < e)
    {
      swap(arr[s++], arr[e--]);
    }
  }
  void rotate(vector<vector<int>> &matrix)
  {
    //         app1

    /////////////////////////////////
    //   r c   00 01 02 03
    //         10 11 12 13
    //         20
    //         30

    ////////////////////////////////////////////
    //         newrow=col;
    //     //         newcol=n-row-1;
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     int newrow=0,newcol=0;
    // vector<vector<int>> mt(n,vector<int>(m));
    // for(int i=0;i<=n-1;i++){
    //     for(int j=0;j<=m-1;j++){
    //         newrow=j;
    //         newcol=n-i-1;
    //         mt[newrow][newcol]=matrix[i][j];
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         matrix[i][j]=mt[i][j];
    //     }
    // }
    // matrix=mt;

    //////////////////////////////////////////////
    // app2
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < m; j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i = 0; i < n; i++)
    {
      reverse(matrix[i]);
    }
  }
};