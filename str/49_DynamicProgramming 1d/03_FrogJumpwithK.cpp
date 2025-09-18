#include<iostream>
#include<bits/stdc++.h>
int solve(int n,vector<int>& heights){
  if(n<=0){
    return 0;
  }
  int curr=0;
  for(int i=0;i<k)
}

using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++){
      cin>>heights[i];
    }
    cout<<solve(n,heights)<<endl;
    vector<int> dp(n,-1);
    cout<<solveBetter(n,heights,dp)<<endl;
    cout<<solveOptimal(heights)<<endl;
    

  }





  return 0;
}











