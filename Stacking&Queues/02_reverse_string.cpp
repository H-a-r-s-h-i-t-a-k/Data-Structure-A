class Solution
{
public:
  string reverse(const string &S)
  {
    // code here
    stack<char> stk;
    stk.push(-1);
    for (char ele : S)
    {
      stk.push(ele);
    }
    string ans = "";
    while (stk.top() != -1)
    {
      ans.push_back(stk.top());
      stk.pop();
    }
    return ans;
  }
};