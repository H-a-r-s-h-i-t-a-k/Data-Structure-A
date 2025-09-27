#include<iostream>
#include<bits/stdc++.h>
#define PI 3.14
using namespace std;
float solve(float  num)
{ float r=(float)num/2;
    float ans=PI *r*r;
return ans;;
}
int main(){
  float num;
  cin>>num;
printf("%.2f ",solve(num));
  return 0;
}

// f/f  f/int   int/f  ==========float