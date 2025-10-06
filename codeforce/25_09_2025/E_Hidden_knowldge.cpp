#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<int> & nums,int n,int k,int l,int r){
  int ans=0;

  unordered_map<int,int>mp;
  set<pair<int,int>> st;

  for(int i=0;i<nums.size();i++){
    int a=nums[i];
    if(mp.find(a)!=mp.end()){
      st.erase({mp[a],a});
    }
    mp[a]=i;
    st.insert({mp[a],a});


    if(st.size()>k+1){
      st.erase(st.begin());
    }

    if(st.size()<k){
      continue;
    }

    int low,high;
    if(st.size()==k){
      low=i-st.begin()->first +1;
      high=i+1;
    }else{
      low=i-(next(st.begin()))->first +1;
      high=i-st.begin()->first;
    }
    low=max(low,l);
    high=min(high,r);

    if(low<=high){
      ans+=high-low+1;
    }




  }

return ans;



}




int32_t main(){
  int t;
  cin>>t;
  while(t--){
    int n,k,l,r;
    cin>>n>>k>>l>>r;

    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    long long ans = solve(nums, n, k, l, r) ;
    cout<<ans<<endl;
  }
  return 0;
}