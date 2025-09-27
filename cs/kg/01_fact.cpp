#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

unsigned int  solve(int num){
 unsigned int ans=1;
  for(int i=2;i<=num;i++){
    ans*=i;
  }
  return ans ;
}
int main(){
  int nums;
  cin>>nums;
  
cout<<solve(nums)<<" ";
  return 0;
}