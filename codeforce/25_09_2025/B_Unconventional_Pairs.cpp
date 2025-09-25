#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums,int n){
  int ans=INT_MAX;
  sort(nums.begin(),nums.end());

for(int i=0;i<n;i++){
  int difmax=0;
  for(int j=i+1;j<n;j+=1){
    difmax=max(difmax,abs(nums[i]-nums[j]));
  }
  ans=min(ans,difmax);

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