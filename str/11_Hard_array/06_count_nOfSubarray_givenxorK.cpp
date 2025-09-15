#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums,int k){
  int n=nums.size();
  int cnt=0;
  int xr=0;
  unordered_map<int,int>mp;
  mp[xr]++;
  for(int i=0;i<n;i++){
    xr^=nums[i];
  
    int x=xr^k;
    cnt+=mp[x];
    mp[xr]++;
  }




  return cnt;
}




int main(){

  int t;
  cin>>t;
  while(t--){

    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
   
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
  
    int ans=solve(nums,k);
  cout<<ans;
  }


  return 0;
}