#include <bits/stdc++.h>
using namespace std;

long long solve(long long n)
{
  long long total = 0;
  long long digit = 5; // start from 5 digits (10000)
  long long comma = 1; // 5–6 digit numbers have 1 comma

  while ((long long)pow(10, digit - 1) <= n)
  {
    long long start = (long long)pow(10, digit - 1);
    long long end = min(n, (long long)pow(10, digit) - 1);

    long long count = end - start ;
    total += count * comma;

    digit++;
    if ((digit - 1) % 3 == 1)
    { // every 3 digits → +1 comma
      comma++;
    }
  }
  return total;
}

int main()
{
  long long t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
