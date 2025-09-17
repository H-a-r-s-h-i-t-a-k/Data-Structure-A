#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(int n){
  if(n<2)return n;
  return solve(n-1)+solve(n-2);
}
int solveBetter(int n,vector<int>&dp){
  if(n<2) {
    dp[n]=n;
    return n;
  }
  //step1
  if(dp[n]!=-1){
    return dp[n];
  }
//  step2
dp[n]=solveBetter(n-1,dp)+solveBetter(n-2,dp);
  return dp[n];
}
int solveOptimal(int n){
  vector<int>dp(n+1,-1);
  dp[0]=0;
  dp[1]=1;
  for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];

  }
  return dp[n];
}
int main(){
  int n;
  cin>>n;
  cout<<solve(n+1)<<endl;
  //step3
  vector<int> dp(n+2,-1);
  cout<<solveBetter(n+1,dp)<<endl;
  cout<<solveOptimal(n+1)<<endl;
  return 0;
}