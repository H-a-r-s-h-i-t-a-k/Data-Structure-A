#include<iostream>
#include<bits/stdc++.h>
using namespace std ;


unsigned int solve(unsigned int a,unsigned int b){
  while(a>0&& b>0){
    if(a>b){
      a=a%b;
    }
    else {
      b=b%a;
    }
  }
  if(a==0){
    return b;
  }
  return a;
}
int main(){
  unsigned int a,b;
  cin>>a>>b;
  cout<<solve(a,b)<<endl;




  return 0;
}