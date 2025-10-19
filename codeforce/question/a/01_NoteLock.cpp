#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;


  while(t--){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
   int prev = INT_MIN;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {

      if(s[i]=='1')
      {
        if(prev < (i - k + 1))
        {
          cnt++;
        }
        prev = i;
      }
    }
    cout << cnt << endl;
  }
  
  return 0;
}