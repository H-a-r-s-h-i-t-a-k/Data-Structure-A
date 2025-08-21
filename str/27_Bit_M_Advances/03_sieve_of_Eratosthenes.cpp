#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  vector<int> prime(n + 1, 1);

  for (int i = 2; i <= n; i++)
  {
    if (prime[i] == 1)
    {
      for (int j = 2 * i; j <= n; j += i)
      {
        prime[j] = 0;
      }
    }
  }
  for (int i = 2; i <= n; i++)
  {
    if (prime[i] == 1)
    {
      cout << i << endl;
    }
  }
  // Write your code here

  return 0;
}