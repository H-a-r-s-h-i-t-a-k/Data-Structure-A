// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// void build(int i,int start,int end,vector<int>&nums,vector<int>&seg){
//   if(start==end){
//     seg[i]=nums[start];
//     return;
//   }
//   int mid=start+(end-start)/2;
//   build(2*i+1,start,mid,nums,seg);
//   build(2*i+2,mid+1,end,nums,seg);
//   seg[i]=seg[2*i+1]+seg[2*i+2];

// }
// int quer(int left,int right,int i,int start,int end,vector<int>&seg){
//   if(left>end|| right<start){
//     return 0;
//   }
//   if(left<=start&& right>=end){
//     return seg[i];
//   }
// int mid=start+ (end-start)/2;

//   return quer(left,right,2*i+1,start,mid,seg)+
//         quer(left,right,2*i+2,mid+1,end,seg);

// }

// vector<int> solve(int n,int q,vector<int>&nums,vector<int>&query){
//   vector<int> ans;
//   vector<int>seg(4*n);
//   build(0,0,n-1,nums,seg);

//   for(int i=0;i<2*q;i+=2){
//     ans.push_back(quer(query[i]-1,query[i+1]-1,0,0,n-1,seg));
//   }
//   return ans;
// }
// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//     int n,q;
//     cin>>n;
//     vector<int>nums(n);
//     for(int i=0;i<n;i++){
//       cin>>nums[i];
//     }
//     cin>>q;
//     vector<int>query(2*q);

//     for(int i=0;i<2*q;i++){
//       cin>>query[i];
//     }
//      vector<int> a= solve(n,q,nums,query);
//      for(auto& num:a){
//       cout<<num<<endl;
//      }
//   }
//   return 0;
// }

// 111111111111111111111111111111111

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//     int n;
//     cin>>n;
//     n=n%3;
//     if(n)
//     cout<< 3-n<<endl;
//     else
//       cout << n << endl;
//   }
//   return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//   int t;
//   cin >> t;
//   while (t--)
//   {
//     int n, k;
//     cin >> n >> k;
//     string str;
//     cin >> str;
//     int cnt = 0;
//     int zero = 0,
//         one = 0, two=0;

// if(n==1){
//   cout<< '-'<<endl;
//   continue;
// }

//     for (auto ch : str)
//     {
//       if (ch == '0')
//       {
//         zero++;
//       }
//       else if (ch == '1')
//       {
//         one++;
//       }
//       else
//       {
//         two++;
//       }
//     }

//     vector<char> ans(n, '+');
//     int i=0;
//     while(zero--){
//       ans[i]='-';
//       i++;
//     }
//     while(two--){
//       ans[i]='?';
//       ans[n-i-1]='?';i++;
//     }
//     int last=n-one;

//     while(last<n){
//       ans[last++]='-';
//     }

//     string answer;
//     for (auto ch : ans)
//     {
//       cout << ch;
//     }

//     cout << endl;
//   }

//   return 0;
// }

#include <iostream>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string str;
    cin >> str;
int ele=str[0],k=0;

    for(auto ch:str){
      if(ele==ch){
        k++;
      }else{
        k--;
        if(k==0){
          ele=ch;
          k=1;
        }
      }
    }
   if(k==n){
    cout<<-1<<endl;
    continue;
   }
   if(k==1){
    cout<<0<<endl;
    continue;
   }





    int cnt = 0;
    int l = 0;
    bool found=false;
    for (int x = 0; x < n; x++)
    {
      if (str[x] == ele)
      {
        cnt++;
      }
      else
      {
        cnt = 0;
        l = x;
      }
      if (cnt == k)
      {
        found = true;

        break;
      }
    }
    if (found)
    {
      cout << k << endl;
    }
    else
    {

      cout << -1 << endl;
    }
  }
  return 0;
}