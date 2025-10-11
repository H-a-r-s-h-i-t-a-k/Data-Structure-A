#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int top,int bottom,int both,int n){
  int topboth=top+both;
  int bottomboth=bottom+both;
  
for(int i=0;i<n;i++){
  if((i<top)||(i>=(n-bottom))){
    cout<<"-";
  }
  else if(( i<topboth)||i>=(n-bottomboth)){
    cout<<"?";
  }
  else{
    cout<<"+";
  }
}
cout<<"\n";
}
 int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;

    string str;
    cin>>str;
    //edges case
    if(n==k){
      for(int i=0;i<k;i++)cout<<"-";
      cout<<"\n";
      continue;
    }


    int top=0,bottom=0;
    int both=0;
    for(auto & s:str){
      if(s=='0') top++;
     else if(s=='1')bottom++;
      else both++;
    }

    solve(top,bottom,both,n);

  }
  return 0;

 }