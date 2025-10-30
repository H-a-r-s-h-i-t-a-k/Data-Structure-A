#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  // cin>>t;
  scanf("%d", &t);
  while (t--)
  {
    int n = 4, i = 0;
    vector<int> nums(n);
    while (i != n)
    {

      scanf("%d", &nums[i]);
      i++;
    }

    i = 1;
    bool flag = false;
    while (i != n)
    {
      if (nums[i] != nums[i - 1])
      {
        flag = true;
        break;
      }
      i++;
    }
    if (flag)
      printf("NO\n");
    else
      printf("yes\n");
  }
  return 0;
}