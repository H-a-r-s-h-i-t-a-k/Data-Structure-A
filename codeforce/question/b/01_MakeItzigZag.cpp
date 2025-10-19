#include<bits/stdc++.h>
using namespace std;
int main(){

  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
int cnt=0;
    int prevmax=nums[0];
    for(int i=0;i<n-1;i++){

      if( nums[i]>=nums[i+1]){
        if(i&1==0){

          if (prevmax > nums[i ])
          {
            nums[i+1]=max(prevmax,nums[i+1]);
  
          }else{
            cnt += abs(nums[i] - nums[i + 1]) + 1;
  
          }
        }
        //odd



      }
      prevmax = max(prevmax, nums[i ]);
    }
    cout<<cnt<<endl;
  }
  return 0;
}