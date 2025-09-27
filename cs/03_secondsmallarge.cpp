#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solvesecondsmall(vector<int>&nums){
  int second=INT_MAX,small= INT_MAX;
int n=nums.size();
  for(int i=0;i<n;i++){
    if(small>nums[i]){
      second=small;
      small=nums[i];
    }
    else if(second>nums[i]&&nums[i]!=small){
      second=nums[i];
    }
  }
  return (second==INT_MAX)?-1:second;
}
int solvesecondlarge(vector<int>& nums){
  int n=nums.size();
  int second=INT_MIN;
  int large=INT_MIN;
  for(int i=0;i<n;i++){
    if(large<nums[i]){
      second=large;
      large=nums[i];
    }else if( second<nums[i]&&nums[i]!=large){
      second=nums[i];
    }
  }
  return second==INT_MIN?-1:second;
}
pair<int,int> solve(vector<int>& nums){

  int small=solvesecondsmall(nums);
  int large=solvesecondlarge(nums);
  return {small,large};
}

int main(){
  int n;
  cin>>n;
  vector<int>nums(n);
  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  pair<int,int> p=solve(nums);
  cout<<p.first<<" "<<p.second<<" "<<endl;





  return 0;
}