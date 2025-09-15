#include<iostream>
#include<bits/stdc++.h>
#include<limits>

using namespace std;
class comp{
  public:
 bool operator()(vector<int>&a, vector<int>&b){
      return a[0]<b[0];
  
  }
};

vector<vector<int>>
solve(vector<vector<int>> &intervals, int n)
{
  vector<vector<int>> ans;
  sort(intervals.begin(),intervals.end(),comp());
 
  for(int i=0;i<n;i++){
   if(ans.empty()||ans.back()[1]<intervals[i][0] ){
    ans.push_back(intervals[i]);

   }else{
    ans.back()[1]=max(ans.back()[1],intervals[i][1]);
   }
  
  }

  return ans;
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>> intervals(n,vector<int>(2));
  for(int i=0;i<n;i++){
   cin>>intervals[i][0]>>intervals[i][1];
  }
  vector<vector<int>> ans;
  ans=solve(intervals,n);
  // ans=solveBetter(intervals,n);
  // ans=solveOptimal(intervals,n);
  for(auto& pair:ans){
    cout<<pair[0]<<" "<<pair[1]<<endl;
  }

  return 0;
}