#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
// #include<bits/stdc++.h>
vector<vector<int>> solveBruteForce(vector<int>& nums){
  vector<vector<int>> ans;
  set<vector<int>> st;
  int n=nums.size();
  sort(nums.begin(),nums.end());
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        int num=nums[i]+nums[j]+nums[k];
        if(num==0){
          st.insert({nums[i],nums[j],nums[k]});
        }
      }
    }
  }
for(auto &list:st){
  ans.push_back(list);
}
   

  // ans.push_back({3,4,5});
  // ans.push_back({2,6,2});
  return ans;
}

vector<vector<int>> solveBetter(vector<int>& nums){
  vector<vector<int>> ans;
  int target=0;
  sort(nums.begin(),nums.end());
  int n=nums.size();
  for(int i=0;i<n;i++){
    if(i>0&& nums[i]==nums[i-1]){
      continue;
    }
    target=-nums[i];
    for(int j=i+1;j<n;j++){
      while(j+1<n&& nums[j]==nums[j+1]){
        j++;
      }
      for(int k=j+1;k<n;k++){
        while(k+1<n && nums[k]==nums[k+1]){
          k++;        }

          if(nums[k]+nums[j]==target){
            ans.push_back({nums[i],nums[j],nums[k]});
          }
      }
    }


  }



  return ans;
}


vector<vector<int>> solveOptimal(vector<int>& nums)
{
  vector<vector<int>>ans;
  int n=nums.size();
  sort(nums.begin(),nums.end());
  int l=0,r=0;
  for(int i=0;i<n-2;i++){
    if(i>0&& nums[i]==nums[i-1]){
      continue;
    }
    l=i+1;
    r=n-1;

    int target=-nums[i];
    while(l<r){
      int sm=nums[l]+nums[r];
      if (sm < target)
      {
        l++;
      }
      else if (sm > target)
      {
        r--;
      }
      else{
        ans.push_back({nums[i],nums[l],nums[r]});
        while(l+1<r&& nums[l]==nums[l+1]){
          l++;
        }
        while(l<r-1 && nums[r]==nums[r-1]){
          r--;
        }
        l++;r--;


      }
    }


  }
  return ans;
}


int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
      cin>>nums[i];

    }
    vector<vector<int>> ans;
    // ans=solveBruteForce(nums);
    // ans=solveBetter(nums);
    ans=solveOptimal(nums);
    for(auto & list:ans){
      for(auto & ele:list){
        cout<<ele<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}