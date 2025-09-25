#include<iostream> 
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>& nums,int day,int B,int size){
  int cnt=0,NoofB=0;
  for(int i=0;i<nums.size();i++){
    if(nums[i]<=day){
      cnt++;

    }else{
      NoofB+=cnt/size;
      cnt=0;
    }
  }
  if(cnt>size){
    NoofB+=cnt/size;
  }

return (NoofB>=B);

}



int solveBrute(vector<int>& nums,int B,int size){
 
  int n=nums.size();
  int maxele=0;
  for(int i=0;i<n;i++){
    maxele=max(maxele,nums[i]);
  }
  for(int i=1;i<=maxele;i++){
  if(isPossible( nums,i,B,size)){
    return i;
  }
  }
  return -1;
}
int main(){
  int t;
  cin>>t;

  while(t--){
    int n,B,size;
    cin>>n>>B>>size;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
      cin>>nums[i];
    }
    cout<<solveBrute(nums,B,size)<<endl;
    // cout<<solveOptimise(nums,B,size)<<endl;

  }


  return 0;
}