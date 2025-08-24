#include <bits/stdc++.h>
#include <algorithm>
// void swap(int& a,int& b){
//    int temp=a;
//    a=b;
//    b=temp;
// }
void sort012(int *arr, int n)
{
  // APP1
  // int one=0,zero=0,two=0;
  // for(int i=0;i<n;i++){
  //    if(arr[i]==0){
  //       zero++;
  //    }
  //    else if(arr[i]==1){
  //       one++;
  //    }else{
  //       two++;
  //    }
  // }
  // int index=0;
  // while(zero){
  //    arr[index++]=0;
  //    zero--;
  // }
  // while(one){
  //    arr[index++]=1;
  //    one--;
  // }
  // while(two){
  //    arr[index++]=2;
  //    two--;
  // }

  // app2

  int I = 0, II = 0, III = n - 1;
  while (II <= III)
  {
    switch (arr[II])
    {
    case 0:
      swap(arr[I++], arr[II++]);
      break;
    case 1:
      II++;
      break;
    case 2:
      swap(arr[II], arr[III--]);
      break;
    }
  }
  //   Write your code here
}