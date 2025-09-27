#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;  
int solve(vector<int>&arr){
  int n=arr.size();
  int small=INT_MAX;

  for(int i=0;i<n;i++){
    small=min(arr[i],small);
  }
  return small;
}
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<solve(arr)<<endl;


  return 0;
}