

// 3 2 
// step h  d


// 0-1 2  1                1-2 0****
// --  3  1
// 1-2 1  2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long solve(int h,int d){
  int curr=0;
  int itr=1;
  long long step=0;
  while(curr!=d){
    if( (h-itr )>=0){
      h-=itr;
      itr++;
      curr++;
    }else{
      h+=1;
    }
    step++;
  }
  return step;
  
}
int main(){

  int t;
  cin>>t;
  while(t--){
    int h,d;
    cin>>h>>d;
    cout<<solve(h,d)<<endl;

  }

   return 0;
}