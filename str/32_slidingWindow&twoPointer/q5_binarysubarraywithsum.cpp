#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
#define int  long long



void solve(vector<int>& nums,int l,int r,vector<int>& ans,unordered_map<int,vector<int>>& freq_map){
  int cnt1=0,cnt2=0;
  int one=LLONG_MIN,two=LLONG_MIN;
  for(int i=l;i<=r;i++ )
  { int num=nums[i];
    if(num==one){
      cnt1++;
    }else if(num==two){
      cnt2++;

    }else if(cnt1==0){
      cnt1=1;
      one=num;

    }else if(cnt2==0){
      cnt2=1;
      two=num;
    }else{
      cnt1--;cnt2--;
    }
  
 
}
  // vector<int>ans(2);
 
int len=r-l+1;
ans.clear();
auto count_in_range = [&](int x)
{
  auto &vec = freq_map[x];
  int c = upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l);
  return c;
};

if (one != LLONG_MIN && count_in_range(one) > len / 3)
  ans.push_back(one);
if (two != LLONG_MIN && two != one && count_in_range(two) > len / 3)
  ans.push_back(two);




}
int32_t main(){
  int t;
  cin>>t;
  while(t--){
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    unordered_map<int, vector<int>> freq_map;
    for(int i=0;i<n;i++){
      cin>>nums[i];
      freq_map[nums[i]].push_back(i);
    }


    int l,r;
    int query=q;
    while(query--){
      cin>>l>>r;
      vector<int> ans;
      l--;r--;
      solve(nums, l, r, ans,freq_map);
      
        if (ans.empty())
          cout << -1; // no majority
        else
        {
          for (int ele : ans)
            cout << ele << " ";
        }
      cout<<endl;
  
    }

  }



  return 0;
}