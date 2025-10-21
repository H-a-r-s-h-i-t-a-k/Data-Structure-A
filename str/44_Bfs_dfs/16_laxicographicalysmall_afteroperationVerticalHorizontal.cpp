#include<bits/stdc++.h>
using namespace std;

string solve(string s,int a,int b){
  string small=s;
  unordered_set<string> visited;
  queue<string>que;
  que.push(s);

  visited.insert(s);
  while(!que.empty()){
    string curr=que.front();que.pop();
    
    if(curr<small){
      small=curr;
    }

    string temp=curr;
    for(int i=1;i<n;i+=2){
      temp[i]= (temp[i]-'0'+a ) -'0';
    }

    if(!visited.count(temp)){
      visited.insert(temp);
      que.push(temp);
    }



    //
    reverse(begin(curr),end(curr));
    reverse(begin(curr),begin(curr)+b);
    reverse(begin(curr)+b,end(curr));

    if(!visited.count(curr)){
      visited.insert(curr);
      que.push(curr);
    }
  }


return small;

}
int main(){
  int t;
  cin>>t;
  while(t--){
     int n,a,b;
     cin>>n;
    string s;

    cin>>s;
     cin>>a>>b;
     cout<<solve(s,a,b)<<endl;
  }
  return 0;
}