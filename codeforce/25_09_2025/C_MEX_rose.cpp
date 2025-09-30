#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;

  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n),freq(n+1,0);
    for(int i=0;i<n;i++){
      cin>>nums[i];
      freq[nums[i]]++;
    }

    int c1=0,c2=freq[k];
    for(int i=0;i<k;i++){
      if(freq[i]==0){
        c1++;
      }
    }
    cout<<max(c1,c2)<<endl;
  }
  return 0;
}