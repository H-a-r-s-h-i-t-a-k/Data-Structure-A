#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int solve(int n,vector<int>&heights){
  if(n<=0) return 0;
  int left=solve(n-1,heights)+abs(heights[n]-heights[n-1]);
  int right=solve(n-2,heights)+ abs(heights[n]-heights[n-2]);
  return min(left,right);
}


int solveBetter(int n,vector<int>&heights,vector<int>& dp){
  if(n==0){
    dp[n]=0;
    return dp[n];

  }
  //step 1
  if(dp[n]!=-1){
    return dp[n];
  }
  int left=solveBetter(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
  int right=solveBetter(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
  // step2
 dp[n]=min(left,right);
 return dp[n];
}

int solveOptimal(vector<int>&heights){
  int n=heights.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int i=1;i<n;i++){
    int left=dp[i-1]+abs(heights[i]-heights[i-1]);
    int right=INT_MAX;
    if(i>1){
      right=dp[i-2]+abs(heights[i-2]-heights[i]);
    }
    dp[i]=min(left,right);
  }
  return dp[n-1];

}


int solveSpace(vector<int>&heights){
  int had=0,have=0;
  int n=heights.size();
  for(int i=1;i<n;i++){
    int left=have+abs(heights[i]-heights[i-1]);
    int right=INT_MAX;
    if(i>1){
      right=had+abs(heights[i-2]-heights[i]);
    }

    int curr=min(left,right);
    had=have;
    have=curr;

  }
  return have;
}











int main(){
  int t;
  cin>>t;
  while(t--){
    int num;
    cin>>num;
    vector<int>heights(num);
    for(int i=0;i<num;i++){
      cin>>heights[i];
    }

    int ans;
    cout<< solve(num-1,heights)<<endl;
    //step3
    vector<int> dp(num+1,-1);
    cout << solveBetter(num-1, heights, dp)<<endl;

    cout << solveOptimal(heights)<<endl;

    cout << solveSpace(heights) << endl;
  }





  return 0;
}