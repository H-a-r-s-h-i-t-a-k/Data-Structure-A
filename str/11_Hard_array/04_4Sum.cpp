#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solvebruteforce(vector<int>& nums,int & target){
  vector<vector<int>> ans;
  sort(nums.begin(),nums.end());

  set<vector<int>> st;
  int n=nums.size();
  for(int i=0;i<=n-4;i++){
    for(int j=i+1;j<=n-3;j++){
      for(int k=j+1;k<=n-2;k++){
        for(int l=k+1;l<=n-1;l++){

          int sm=nums[i]+nums[j]+nums[k]+nums[l];
          if(sm==target){
            st.insert({nums[i],nums[j],nums[k],nums[l]});
          }
        }
      }
    }

  }

  for( auto& list:st){
    ans.push_back(list);
  }
  return ans;
}

   vector<vector<int>> solveBetter(vector<int>& nums,int &target){
vector<vector<int>> ans;

int n = nums.size();
sort(nums.begin(), nums.end());

for (int i = 0; i <= n - 4; i++)
{
  if (i > 0 && nums[i] == nums[i - 1])
  {
    continue;
  }
  for (int j = i + 1; j <= n - 3; j++)
  {
    if (j > i + 1 && nums[j] == nums[j - 1])
    {
      continue;
    }
    for (int k = j + 1; k <= n - 2; k++)
    {
      if (j + 1 < k && nums[k] == nums[k - 1])
      {
        continue;
      }
      for (int l = k + 1; l <= n - 1; l++)
      {
        if (k + 1 < l && nums[l] == nums[l - 1])
        {
          continue;
        }

        if (target == (long long)nums[i] + nums[j] + nums[k] + nums[l])
        {
          ans.push_back({nums[i], nums[j], nums[k], nums[l]});
        }
      }
    }
  }
}
return ans;
}


vector<vector<int>> solveOptimal(vector<int>& nums, int target){
  vector<vector<int>> ans;
  int n= nums.size();
  sort(nums.begin(),nums.end());

  for(int i=0;i<=n-4;i++){
    if(i>0&& nums[i]==nums[i-1]){
      continue;
    }
    for(int j=i+1;j<=n-3;j++){
      if(j>i+1&& nums[j]==nums[j-1]){
        continue;
      }

      int left=j+1,right=n-1;

      while(left<right){
        long long sum4=(long long ) nums[i]+nums[j]+nums[left]+nums[right];

        if(sum4==target){
          while(left+1<right&& nums[left]==nums[left+1]) left++;
          while(left< right-1&& nums[right]== nums[right-1])right--;

          ans.push_back({nums[i],nums[j],nums[left],nums[right]});
          left++;
          right--;
        }

        else if(sum4<target){
          left++;
        }else{
          right--;
        }
      }
    }
  }
  return ans;
}
int  main(){
  int t,n,target;
  cin>>t;
  while(t--){
    cin>>n;
    cin>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    vector<vector<int>> ans;
    // ans=solvebruteforce(nums,target);
    // ans=solveBetter(nums,target);
    ans=solveOptimal(nums,target);

    for(auto & list:ans){
      for(auto& ele: list){
        cout<<ele<<" ";
      }
      cout<<endl;
    }
  }





   return 0;

}