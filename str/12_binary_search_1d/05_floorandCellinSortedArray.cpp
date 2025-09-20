#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solvelower(vector<int>& nums,int target){
  int index=-1;
  int left=0,right=nums.size()-1;
  while(left<=right){
    int mid=left+(right-left)/2;
    if(nums[mid]==target){
      index=mid;
      right=mid-1;

    }else if (nums[mid]<target){
      left=mid+1;
    }else{
      right=mid-1;
    }
  }

  return (index==-1)?left-1:index;
}
int solveupper(vector<int> &nums, int target)
{
  int index = -1;
  int left = 0, right = nums.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      index = mid;
      left = mid + 1;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  return (index == -1) ? left  : index;
}

pair<int,int> solve(vector<int>&nums,int target){
  int floor=-1,ceil=-1;
  floor=solvelower(nums,target);
  ceil=solveupper(nums,target);
  return {nums[floor],nums[ceil]};
}



int main(){
  int t;
  cin>>t;



  while(t--){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<nums.size();i++){
      cin>>nums[i];
    }


    pair<int,int> p=solve(nums,target);
    cout<<p.first<<" "<<p.second<<endl;
  }
  return 0;
}