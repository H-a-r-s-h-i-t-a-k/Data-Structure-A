#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

 class graph{
  public:
  unordered_map<int,list<int>>adj;
  void addedges(int u,int v,bool dir){
    adj[u].push_back(v);
    if(dir){
      adj[v].push_back(u);
    }
  }

  void printgraph(){
    for(auto& i:adj){
      cout<<i.first<<"-> ";
      for(auto&x: i.second){
        cout<<x<<" ";
      }
      cout<<endl;
    }

  }



 };
 int main(){
  graph g;
  g.addedges(1,0,1);
  g.addedges(1,2,1);
  g.addedges(0,2,1);
  g.addedges(2,3,1);
  g.printgraph();
 }