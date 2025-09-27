#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
void solve(vector<int>& nums){
  int n=nums.size();
  map<int,int> mp;
  for(int i=0;i<n;i++){
    mp[nums[i]]++;
  }
  vector<int> ans;
  for(auto& ele: mp){
    ans.push_back(ele.second);
  }
  for(auto& item:ans){
    cout<<item<<" ";
  }
}
int main(){
  int n;
  cin>>n;
  vector<int>nums(n);
  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  solve(nums);
  return 0;
}