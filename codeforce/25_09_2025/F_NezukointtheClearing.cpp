

// 3 2 
// step h  d


// 0-1 2  1                1-2 0****
// --  3  1
// 1-2 1  2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve(int  h,int d){
  int low=d,high=2*d-1;
  int ans=2*d;
  while(low<=high)
{
  int mid=low+ (high-low)/2;
  int x=mid-d+1;
  int s1=(d/x)*(d/x+1)/2;
  int s2=(d/x+1)*(d/x+2)/2;
  int s=(x-d%x)*s1 +(d%x)*s2;
  if(s<h+ mid-d){
    ans=mid;
    high=mid-1;
  }else{
    low=mid+1;
  }
}
  return ans;
}
int32_t main(){

  int t;
  cin>>t;
  while(t--){
    int h,d;
    cin>>h>>d;
    cout<<solve(h,d)<<endl;

  }

   return 0;
}