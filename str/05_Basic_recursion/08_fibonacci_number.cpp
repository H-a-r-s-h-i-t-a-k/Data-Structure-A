#include <bits/stdc++.h>
const int mod = 1e9 + 7;
int fibonacciNumber(int n)
{
  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  }
  return dp[n] % mod;
  // Write your code here.
}

// #include <bits/stdc++.h>
// const int mod =1e9+7;

// int fibonacciNumber(int n){
//     if(n==0)return 0;
//     if(n==1)return 1;
//     return ( fibonacciNumber(n-1)+fibonacciNumber(n-2))%mod;

//     // Write your code here.
// }

#include <bits/stdc++.h>
const int mod = 1e9 + 7;
int fibonacciNumber(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int had = 0;
  int have = 1;
  for (int i = 2; i <= n; i++)
  {
    int curr = (have + had) % mod;
    had = have;
    have = curr;
  }
  return have;
  // Write your code here.
}

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef vector<vector<long long>> Matrix;

Matrix multiply(Matrix &A, Matrix &B)
{

  int size = A.size();

  Matrix C(size, vector<long long>(size, 0));

  for (int i = 0; i < size; i++)
  {

    for (int j = 0; j < size; j++)
    {

      for (int k = 0; k < size; k++)
      {

        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }

  return C;
}

Matrix matrixExpo(Matrix base, int exp)
{

  int size = base.size();

  Matrix result(size, vector<long long>(size, 0));

  for (int i = 0; i < size; i++)
    result[i][i] = 1; // Identity matrix

  while (exp > 0)
  {

    if (exp % 2 == 1)
      result = multiply(result, base);

    base = multiply(base, base);

    exp /= 2;
  }

  return result;
}

int fibonacciNumber(int N)
{

  // Write your code here.

  if (N <= 2)
    return 1;

  Matrix F = {{1, 1}, {1, 0}};

  F = matrixExpo(F, N - 2);

  return (F[0][0] + F[0][1]) % MOD;
