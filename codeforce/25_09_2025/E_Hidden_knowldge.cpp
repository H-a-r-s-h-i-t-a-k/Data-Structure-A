#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int>& nums,int n,int k,int l,int r){
  long long number = 0;
  int left=0;int right=0;
  unordered_map<int,int> mp;

  for(right=0;right<n;right++){
    mp[nums[right]]++;
    while(mp.size()>k){
      mp[nums[left]]--;
      if(mp[nums[left]]==0){
        mp.erase(nums[left]);
      }
      left++;
    }
     
      
      int len=right-left+1;
      if(len>=l){
        number+=min(len,r)-l+1;
      }
    
    
  

  
}
  return number;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k,l,r;
    cin>>n>>k>>l>>r;

    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    long long ans = solve(nums, n, k, l, r) - solve(nums, n, k - 1, l, r);
    cout<<ans<<endl;
  }
  return 0;
}