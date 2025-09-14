#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>


using namespace std;


string solveStep3(unordered_map<string,int>&mp, string & word){
  string ans="";
  
  for( auto & given:mp){
    if(given.size()!=word.size()){
      ans="";
      continue;
    }
    for()
  }
}




vector<string> solve(vector<string>& wordlist,vector<string>& queries){
  vector<string> ans;
  unordered_map<string,int> mp;
  for(auto&word: wordlist){
    mp[word]++;
  }
  for(auto& q:queries){
    if(mp[q]){
      ans.push_back(q);
    continue;
    }
    string lower=q.lower();
    for(auto& key:mp){
      string low=key.lower();
      if(lower==low){
        ans.push_back(key);
        continue;
      }
    }

    string step3=solveStep3(mp,word);
    ans.push_back(step3);


  }

}
int main(){
  int t,w,q;
  cin>>t;
  while(t--){
    cin>>w;
    vector<string> wordlist;
    while(w--){
      string s;
      cin>>s;
      wordlist.push_back(s);
      
    }
    cin>>q;
    vector<string> queries;
    while(q--){
      cin>>q;
      string s;
      cin>>s;
      queries.push_back(s);

    }
    vector<string> ans=solve(wordlist,queries);
    for(auto& word:ans){
      cout<<word<<" ";
    }
    cout<<endl;
  }
  return 0;
}