class Solution {
  public:
  
    void solve(stack<int>& s,int ind,int n){
        if(ind==(n/2)){
            s.pop();
            return;
        }
        int num=s.top();
        s.pop();
        
        solve(s,ind+1,n);
        s.push(num);
        return;
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int n=s.size();
    solve(s,0,n);
    }
};