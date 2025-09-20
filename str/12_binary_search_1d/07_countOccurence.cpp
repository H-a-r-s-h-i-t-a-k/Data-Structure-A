#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lowerOccurence(vector<int>&nums,int &target){

  int left=0,right=nums.size()-1,index=-1;
  while(left<=right){
    int mid=left+(right-left)/2;
    if(target==nums[mid]){
    index=mid;
      right=mid-1;
    }else if(target<nums[mid]){
      right=mid-1;
    }
    else{
      left=mid+1;
    }
  }
  return index;
}

int upperOccurence(vector<int>& nums,int &target){
  int index=-1;
  int left=0,right=nums.size()-1;
  while(left<=right){
    int mid=left+(right-left)/2;
    if(nums[mid]==target){
      index=mid;
      left=mid+1;

    }else if(nums[mid]<target){
      left=mid+1;
    }else{
      right=mid-1;
    }
  }
  return index;

}



int countOccurence(vector<int>&nums,int & target){
  int lower=lowerOccurence(nums,target);
  int upper=upperOccurence(nums,target);
  int cnt=upper-lower+1;
  return cnt;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    cout<<countOccurence(nums,target)<<endl;
  }


  return 0;
}