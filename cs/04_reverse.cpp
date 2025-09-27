#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums){
  int left=0;int right=nums.size()-1;
  while(left<right){
    swap(nums[left++],nums[right--]);
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
for(int i=0;i<n;i++){
  cout<<nums[i]<<" ";
}

  return 0;
}