#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int solve(vector<int>& arr){
  int large=INT_MIN;
  int n=arr.size();
  for(int i=0;i<n;i++){
    large=max(arr[i],large);
  }
  return large;
}
int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<solve(arr)<<endl;
  return 0;
}