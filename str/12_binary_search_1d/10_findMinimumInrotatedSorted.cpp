#include<iostream>
#include<vector>

// #include<bits/stdc++.h>
#include<limits.h>

using namespace std;

int solve(vector<int>& nums){
  int left=0,right=nums.size()-1,ans=INT_MAX;
  while(left<=right){
    int mid=left+(right-left)/2;
if(nums[left]<=nums[right]){
  ans=min(ans,nums[left]);
  return ans;
}
    if(nums[left]<=nums[mid]){
      ans=min(ans,nums[left]);
      left=mid+1;
    }
    else{
      ans=min(ans,nums[mid]);
      right=mid-1;
    }
  }
  return ans;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    vector<int> nums(n);
    for(int i=0;i<nums.size();i++){
      cin>>nums[i];
    }
    cout<<solve(nums)<<endl;
  }






  return 0;
}