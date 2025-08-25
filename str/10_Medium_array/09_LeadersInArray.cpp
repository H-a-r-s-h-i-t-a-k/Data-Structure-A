#include <bits/stdc++.h>
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
void reverse(vector<int> &arr)
{
  int s = 0, e = arr.size() - 1;
  while (s <= e)
  {
    swap(arr[s++], arr[e--]);
  }
}
vector<int> findLeaders(vector<int> &elements, int n)
{
  // app1

  // vector<int>ans;
  // for(int i=0;i<n;i++){
  //     if(i+1<n && elements[i]==elements[i+1]){
  //         continue;
  //     }
  //     int mayLeader=elements[i];
  //     bool success=true;
  //     for(int j=i+1;j<n;j++){
  //        if(mayLeader==elements[j]){
  //            continue;
  //        }
  //         if(mayLeader<elements[j]){
  //             mayLeader=-1;
  //             success=false;
  //             break;
  //         }
  //     }
  //         if(success){
  //         if(ans.empty()|| ans.back()!=mayLeader){

  //         ans.push_back(mayLeader);
  //         }
  //         }
  // }
  // // sort(ans.begin(),ans.end());
  // return ans;

  // app2
  vector<int> ans;

  // int n=elements.size();
  ans.push_back(elements[n - 1]);
  int maxfromR = elements[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    if (elements[i] > maxfromR)
    {
      ans.push_back(elements[i]);
      maxfromR = elements[i];
    }
  }
  reverse(ans);
  return ans;

  // Write your code here.
}