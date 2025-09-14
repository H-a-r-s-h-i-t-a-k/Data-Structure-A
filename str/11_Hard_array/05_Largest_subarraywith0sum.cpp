 #include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;


 int solve(vector<int>& arr,int &n,int &k){
  int maxlen=0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int sum=0;
      for(int k=i;k<=j;k++){
        sum+=arr[k];
        if(sum==0){
          int len=k-i+1;
          maxlen=max(len,maxlen);
        }
      }

    }
  }
  return maxlen;
 }

 int solveBetter(vector<int>&arr,int &n,int&k){
   int maxlen = 0;
   for (int i = 0; i < n; i++)
   {
     int sum = 0;
     for (int j = i; j < n; j++)
     {
       sum += arr[j];
       if (sum == 0 && maxlen < j - i + 1)
       {
         maxlen = max(maxlen, (j - i + 1));
       }
     }
   }
   return maxlen;
 }

 int solveOptimal(vector<int>& arr,int n,int k){
   unordered_map<int, int> mp;
   int maxlen = 0;
   // prefixsum,index
   int prefixsum = 0;
   for (int i = 0; i < n; i++)
   {
     prefixsum += arr[i];

     if (prefixsum == k)
     {
       maxlen = i + 1;
     }
     else
     {
       if (mp.find(prefixsum) != mp.end())
       {

         int len = i - mp[prefixsum];
         maxlen = max(maxlen, len);
       }
       else
       {

         mp[prefixsum] = i;
       }
     }
   }

   return maxlen;
 }
 int main(){
  int n=0;
  cin>>n;
  int k=0;
  cin>>k;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int ans;
  //  ans=solve(arr,n,k);
   ans=solveBetter(arr,n,k);
  //  ans=solveOptimal(arr,n,k);
  cout<<ans<<endl;
  return 0;
 }