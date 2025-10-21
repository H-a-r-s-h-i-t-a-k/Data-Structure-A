// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//     string str;
//     cin>>str;
//     int s=str.length();
//    int n=0;
// int i=0;
//     while(s!=0&&str[s-1]!='-'){
//       if(str[s-1]==' ') break;
//       int digit=str[s-1]-'0';
//       n= n+(digit*pow(10,i));
// s--;i++;
//     }
//     n*=-1;
//     cout<<n<<endl;
//   }
//   return 0;
// }


// above is my code


#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
const int INT_MAX_VAL =2147483647;
 const int INT_MIN_VAL =-2147483648;


int helper(const string & s,int i,long long num,int sign){

    if(i>=s.length()  || !isdigit(s[i])) {
      return (int) (sign*num);
    }
num=num*10+(s[i]-'0');

    if( sign* num >= INT_MAX_VAL) return INT_MAX_VAL;
     if(sign*num<= INT_MIN_VAL) return INT_MIN_VAL;
    
      return helper(s,i+1,num,sign);
    





}













int myatoi( string s,int i=0){
  while(  i<s.size()   && s[i]==' ') i++;
int sign =1;
  if(i<s.size()&& ( s[i]=='+' || s[i]=='-')){
     sign=(s[i]=='-')?-1:1;
    i++;
  }

  return helper(s,i,0,sign);



}
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;

    printf("%d\n",myatoi(s));
  }
  return 0;

}













