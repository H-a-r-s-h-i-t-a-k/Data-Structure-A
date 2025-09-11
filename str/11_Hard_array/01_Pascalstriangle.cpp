#include<iostream>

#include<vector>
using namespace std;

// format 1
// given r&c and find value of that index

// format 2
// print any nth row in pascaltriangle

// format 3
// entire pascal trinagle

// nCr = n!/r!(n-r)!;
// Combination r-1 C c-1
// 10C3   10 *9*7  / 3*2*1;
// // 10/1  * 9/2 *8/3;


// // apppp1
// // find out each element using the combination formula 
// int funNcR(int n,int r){
//   int res=1;
//   for(int i=0;i<r;i++){
//     res=res* (n-i )/(i+1);
//   }
//   return res;
// }
// vector<vector<int>> generate(int numRows){
// vector<vector<int>> ans;
  
//   for(int i=0;i<numRows;i++){
//     vector<int> rowelement;
//     for(int j=0;j<i+1;j++){
//       rowelement.push_back(funNcR(i,j));
//     }
//     ans.push_back(rowelement);
//   }
//   return ans;
// }

// // row elment
// // appp2
// #include <bits/stdc++.h>
//     using namespace std;
// // unsigned long long funNcR(int n, int r)
// {
//   unsigned long long res = 1;
//   for (int i = 0; i < r; i++)
//   {
//     res = res * (n - i) / (i + 1);
//   }
//   return res;
// }
// vector<unsigned long long> generate(int r)
// {
//   vector<unsigned long long> rowElement;
//   for (int j = 0; j <= r; j++)
//   {
//     rowElement.push_back(funNcR(r, j));
//   }
//   return rowElement;
// }


// Appp3 Optimize

// //     0 1 2  3  4  5 
// //     1 5 10 10 5 1 
// // res=1
// //     1* 5/1
// //     1* 5/1 *4/2
// //      1* 5/1 *4/2 *3/3 and so on so drive a formula is
// //    res=  res* (row-col)/col;


// void printNthrow(int r){
//   int res=1;
//   cout<<1<<" ";
//   for(int col=1;col<r;col++){
//     res=res*(r-col)/col;
//     cout<<res<<" ";
//  }
//  cout<<endl;
// }

// int main()
// {
//   int t, n;
//   cin >> t;
//   while (t--)
//   {
//     cin >> n;
//     // vector<unsigned long long> ans = generate((n - 1));

//     // for (int i = 0; i <= n - 1; i++)
//     // {
//     //   cout << ans[i] << " ";
//     // }
//     // cout << endl;
//     printNthrow(n);
//   }
//   return 0;
//   // your code goes here
// }

// int main(){
//   int n;
//   cin>>n;
//   vector<vector<int>> res=generate(n);
//   // int r=res.size();
//   // int c=res[0].size();
//   for(int i=0;i<n;i++){
//     for(int j=0;j<res[i].size();j++){
//       cout<<res[i][j]<<" ";
//     }
//     cout<<endl;
//   }

//   return 0;
// }







// format 3 print entire
#include<iostream>

using namespace std;
int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    for(int r=1;r<=n;r++){
      unsigned long long res=1;
      cout<<res<<" ";
      for(int col=1;col<r;col++) {
        res=res*(r-col)/col;
        cout<<res<<" ";
      }
      cout<<endl;

    }
  }
  return 0;
}



