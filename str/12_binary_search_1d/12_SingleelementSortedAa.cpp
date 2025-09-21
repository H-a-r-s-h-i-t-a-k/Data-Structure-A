#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solveBrute(vector<int>&nums){
  int n=nums.size();
  if(n==1)return nums[0];
  if(nums[0]!=nums[1]){
    return nums[0];
  }
  if(nums[n-1]!=nums[n-2]){
    return nums[n-1];
  }
  int left=1,right=n-2;
 while(left<=right){
    int mid=left+(right-left)/2;

    if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
      return nums[mid];
    }


    if((mid&1)==1&& nums[mid]==nums[mid-1]  || (mid&1)==0 && nums[mid]==nums[mid+1]){
      left=mid+1;

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
    // cout<<solveOptimise(nums)<<endl;
// 
  }
  return 0;

}