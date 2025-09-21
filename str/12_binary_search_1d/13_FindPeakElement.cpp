#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


int solveBrute(vector<int>& nums){
  for(int i=0;i<nums.size();i++){
    if(
      ((i==0)|| nums[i]>nums[i-1]) 
    && ((i==nums.size()-1 )|| nums[i]>nums[i+1] )){
      return i;
    }
  }
}
int solveOptimise(vector<int>&nums){
  int n=nums.size();
  if(n==1)return 0;
  if(nums[n-1]>nums[n-2])return n-1;
  if(nums[0]>nums[1])return 0;

  int left=1,right=n-2;
  while(left<=right){
    int mid=left+(right-left)/2;
    if((nums[mid]>nums[mid-1])&&(nums[mid]>nums[mid+1])){
      return mid;
    }
    else if (nums[mid]>nums[mid-1]){
      left=mid+1;
    }else if(nums[mid]>nums[mid+1]){
      right=mid-1;
    }else{
      right=mid-1;
    }
  }


return -1;
}
int main(){

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    cout<<solveBrute(nums)<<endl;
    cout<<solveOptimise(nums)<<endl;
  }
  return 0;
}