#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
long long power(int num,int k,int n)
  {
    long long ans=1;
    for(int i=0;i<k;i++){
      ans*=num;
      if(ans> n){
        return 2;
      }

    }
    if(ans==n)return 1;
    return 0;

}
int solve(int k,int n)
{
  int left = 0, right = n;
  while (left <= right)
  {
    long long mid = left + (right - left) / 2;
    long long multi = power(mid, k, n);
    if (multi == 1)
    {

     return mid;
    }else if(multi==0){
      left=mid+1;
    }
    else
    {
      right = mid - 1;
    }
  }

  return -1;
}
int main()
{
  int n,k;
  cin >> n>>k;

  cout << solve(n,k) << endl;

  return 0;
}