#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int dif=count(s.begin(),s.end(),'a')-count(s.begin(),s.end(),'b');

    map<int,int>mp;
    mp[0]=-1;
int ans=n;
    int prev=0;
    for(int i=0;i<n;i++ ){
      prev+=  s[i]=='a'? 1:-1;
      mp[prev]=i;
      if( mp.count(prev-dif)){
        ans=min(ans,i-mp[prev-dif]);
      }





    }

cout<< (ans==n?-1:ans)<<endl;





  }

  return 0;
}