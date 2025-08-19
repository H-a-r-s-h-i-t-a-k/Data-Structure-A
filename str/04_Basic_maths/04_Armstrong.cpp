#include <bits/stdc++.h>
bool isArmstrong(int num)
{
  if (num < 0)
  {
    return false;
  }
  int n = floor(log10(num)) + 1;
  int copy = num;
  int arm = 0;
  while (num > 0)
  {
    int last = num % 10;
    num /= 10;
    arm = arm + pow(last, n);
  }
  return arm == copy;
  // Write your code here
}