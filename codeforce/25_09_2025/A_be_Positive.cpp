#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n){
  int ans=0;
  int negative=0;
  int zero=0;
  for(auto& ele:nums){
    if(ele==-1){
      negative++;
    }else if(ele== 0){
      zero++;
    }
  }
  if((negative&1)){
    ans+=2;
  }
  ans+=zero;
  
  
  return ans;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    cout<<solve(nums,n)<<endl;
  }




  return 0;
}