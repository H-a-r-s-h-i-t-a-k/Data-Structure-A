#include <bits/stdc++.h>
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{

  // app1

  // vector<int> row(n,1);
  // vector<int>col(m,1);

  // for(int i=0;i<=n-1;i++){
  // 	for(int j=0;j<=m-1;j++){
  // 		if(matrix[i][j]==0){
  // 			row[i]=0;
  // 			col[j]=0;
  // 		}
  // 	}
  // }
  // for(int i=0;i<n;i++){
  // 	for(int j=0;j<m;j++){
  // 		if(row[i]==0||col[j]==0){
  // 			matrix[i][j]=0;
  // 		}
  // 	}
  // }
  // return matrix;

  // app2
  bool row = false, col = false;
  for (int i = 0; i < m; i++)
  {
    if (matrix[0][i] == 0)
    {
      row = 1;
      break;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (matrix[i][0] == 0)
    {
      col = 1;
      break;
    }
  }

  int temp = matrix[0][0];
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (matrix[i][j] == 0)
      {
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
    }
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (matrix[i][0] == 0 || matrix[0][j] == 0)
      {
        matrix[i][j] = 0;
      }
    }
  }
  if (col)
  {
    for (int i = 0; i < n; i++)
    {
      matrix[i][0];
    }
  }
  if (row)
  {
    for (int i = 0; i < m; i++)
    {
      matrix[0][i];
    }
  }
  return matrix;

  // Write your code here.
}