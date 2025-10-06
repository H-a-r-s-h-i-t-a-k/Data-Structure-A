#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void build(int i,int start,int end,vector<int>&nums,vector<int>&seg){
  if(start==end){
    seg[i]=nums[start];
    return;
  }
  int mid=start+(end-start)/2;
  build(2*i+1,start,mid,nums,seg);
  build(2*i+2,mid+1,end,nums,seg);
  seg[i]=seg[2*i+1]+seg[2*i+2];


}
int quer(int left,int right,int i,int start,int end,vector<int>&seg){
  if(left>end|| right<start){
    return 0;
  }
  if(left<=start&& right>=end){
    return seg[i];
  }
int mid=start+ (end-start)/2;

  return quer(left,right,2*i+1,start,mid,seg)+
        quer(left,right,2*i+2,mid+1,end,seg);



}

vector<int> solve(int n,int q,vector<int>&nums,vector<int>&query){
  vector<int> ans;
  vector<int>seg(4*n);
  build(0,0,n-1,nums,seg);

  for(int i=0;i<2*q;i+=2){
    ans.push_back(quer(query[i]-1,query[i+1]-1,0,0,n-1,seg));
  }
  return ans;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,q;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    cin>>q;
    vector<int>query(2*q);

    for(int i=0;i<2*q;i++){
      cin>>query[i];
    }
     vector<int> a= solve(n,q,nums,query);
     for(auto& num:a){
      cout<<num<<endl;
     }
  }
  return 0;
}