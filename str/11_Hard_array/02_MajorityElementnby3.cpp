#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
// intution  at max  how many integer will be > n/3
// 14/3 =4   --5 ,5 ,5==15  only two element can be >n/3

// Brute force 
 vector<int> solveBruteForce(vector<int>&nums){
  int n=nums.size(),thresh=n/3;
  vector<int>ans;
  for(int i=0;i<n;i++){
    int cnt=0;
    if(count(ans.begin(),ans.end(),nums[i])>0){
      continue;
    }
    for(int j=i;j<n;j++){
      if(nums[i]==nums[j]){
        cnt++;
      }
    }
    if(cnt>thresh){
      ans.push_back(nums[i]);
    }
  }
  return ans;
 }
//Better
vector<int> solveBetter(vector<int>&nums){
  int n=nums.size();
  unordered_map<int,int>mp;
  int thresh=(int)n/3+1;
  vector<int>ans;
  for(int i=0;i<n;i++){
    mp[nums[i]]++;
    if(mp[nums[i]]==thresh){
      ans.push_back(nums[i]);
    }
    if(ans.size()==2)break;
  }
 sort(ans.begin(),ans.end());
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
    // vector<int> ans=solveBruteForce(nums);
    vector<int> ans=solveBetter(nums);
    for(auto &ele:ans){
      cout<< ele<<" ";
    }
    cout<<endl;
  }


  return 0;
}