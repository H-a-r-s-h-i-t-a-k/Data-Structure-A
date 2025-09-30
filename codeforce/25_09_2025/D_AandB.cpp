#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF =1e18;
int solve(string &s,int& n){
  vector<int>pra (n,0),prb(n,0),cnt(n,0);
  cnt[0]=s[0]=='a';

  for(int i=1;i<n;i++){
    pra[i]=pra[i-1];
    prb[i]=prb[i-1];
    cnt[i]=cnt[i-1];

    if(s[i]=='a'){
      cnt[i]++;
      prb[i]+=(i+1)-cnt[i];

    }else{
      pra[i]+=cnt[i];
    }




  }

  vector<int> sufa(n,0),sufb(n,0),scnt(n,0);
  scnt[n-1]=s[n-1]=='a';
  for(int i=n-2;i>=0;i--){
    sufa[i]=sufa[i+1];
    sufb[i]=sufb[i+1];
    scnt[i]=scnt[i+1];
    if(s[i]=='a')
    { scnt[i]++;
      sufb[i]+=(n-i)- scnt[i];
    
    }else{
      sufa[i]+=scnt[i];
    }


  }



  int ans=INF;

  for(int i=0;i<n;i++){
    ans=min({ans,pra[i]+sufa[i],prb[i]+sufb[i]});

  }





return ans;






}
int32_t main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    int n;

    cin>>n;
    cin>>s;

    cout<<solve(s,n)<<endl;
  }



   return 0;
}


