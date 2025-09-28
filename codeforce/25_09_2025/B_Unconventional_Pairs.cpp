#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums,int n){
  int ans=0;
  sort(nums.begin(),nums.end());

for(int i=0;i<n;i+=2){
  int difmax=(nums[i+1]-nums[i]);
  
  ans=max(ans,difmax);

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
    cout<<solve(nums,n)<<endl;
  }




  return 0;
}