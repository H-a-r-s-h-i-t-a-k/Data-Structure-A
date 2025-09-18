#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int target){
  int index=-1;
  int left=0,right=nums.size()-1;
  while(left<=right){
    int mid=left+(right-left)/2;
    if(nums[mid]==target){
      index=mid;
      break;
    }
    else if(nums[mid]<target){
      left=mid+1;

    }
    else{
      right=mid-1;
    }
  }

  return (index==-1)?left:index;
}
int main(){

  int t;
  cin>>t;
  while(t--)
  {
    int n,target;
    cin>>n>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    cout<<solve(nums,target)<<endl;

  }
  return 0;
}