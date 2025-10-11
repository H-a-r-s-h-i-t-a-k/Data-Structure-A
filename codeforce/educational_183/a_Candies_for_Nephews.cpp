#include<iostream>
using namespace std;
#include<bits/stdc++.h>



int main(){
  int n;
  cin>>n;
  while(n--){
    int num;
    cin>>num;
    cout<<( num%3 ? 3- num%3: 0)<<endl;
  }
  return 0;
}