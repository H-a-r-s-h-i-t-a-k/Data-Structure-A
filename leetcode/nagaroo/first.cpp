#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums,int k){
  sort(nums.begin(),nums.end());
  int n=nums.size();
  int l=0,r=n-1;
  int lowest=INT_MAX;
  while(l<r){
    if((nums[l]+nums[r])  % k==0  ){
      lowest=min(lowest,nums[l]);
      
    }
    l++;r--;
  }
  if(l==r){
    if((nums[l]*2 ) %k==0)
    lowest=min(lowest,nums[l]);
  }
  return lowest;
}
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>nums(n);
  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  int ans=solve(nums,k);
  cout<<ans;
  return 0;
}