#include <bits/stdc++.h>
int countDigit(long long x)
{

  int c = 0;
  while (x > 0)
  {
    c++;
    x = x / 10;
  }

  ///////////////2//////////
  printf("%d",floor(log10(x))+1);
  return c;
  // Write your code here.
}