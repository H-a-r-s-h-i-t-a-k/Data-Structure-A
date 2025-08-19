void solve(int i,int n,vector<int>& ans){
  if(i>n){
    return ;
  }
  solve(i+1,n,ans);
  ans.push_back(i);
}
vector<int >reverse(int n){
  vector<int> ans;
  solve(1,n,ans);
  return ans;
}