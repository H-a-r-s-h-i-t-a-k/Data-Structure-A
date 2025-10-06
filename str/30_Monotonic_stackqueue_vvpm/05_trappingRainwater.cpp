#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<int>& nums){
  int left=0;int right=n-1;
  int ans=0;

  while(left<=right){
    if(nums[left]<nums[right] ){
      ans=max(ans, nums[left]*(right-left));
      left++;
    }
    else if(nums[left]>nums[right]){
      ans=max(ans,nums[right]*(right-left));
      right--;
    }else{

      ans = max(ans, nums[left] * (right - left ));
      left++;
      right--;
    }
    
  }
  return ans;
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
    cout<<solve(n,nums)<<endl;
  }
  return 0;
}