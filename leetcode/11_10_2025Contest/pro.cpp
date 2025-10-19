// #include<bits/stdc++.h>
// using namespace std;
// bool solve(string s){
//   unordered_map<int ,int>mp;
//   mp[0]=-1;
// int pref=0;
//   for(int i=0;i<s.size();i++){
//     pref+=s[i]-'a';
//     if(mp.find(pref/2)!=mp.end()){
//       return true;
//     }
//     mp[pref]=i;
//   }
//   return false;
// }
// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//     string str;
//     cin>>str;
//     cout<<(solve(str)?"true":"false")<<endl;
//   }

//   return 0;
// }



///////////////////2/////////////////
#include<bits/stdc++.h>
using namespace std;



int solve(vector<int>& nums){
  int n=nums.size();
int len=1;
int ans=1;
  for(int i=1;i<n;i++){
   if( (i>1) && ((nums[i-1]+nums[i-2])==  nums[i])){
    if(len<2) len=2;  
    len++;
      ans=max(len,ans);

    }
    else if(nums[i] == nums[i - 1])
    {
      len = 2;
    }
  }

return ans;



}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>str(n);
  for(int i=0;i<n;i++){
    cin>>str[i];
  }

   cout<< solve(str)<<endl;
  }



  return 0;
}