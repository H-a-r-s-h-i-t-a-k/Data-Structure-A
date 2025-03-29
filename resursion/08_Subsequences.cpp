#include <bits/stdc++.h>

void solve(string str, vector<string> &ans, int i, int n, string opt)
{
    if (i >= n && opt.length() >= 1)
    {
        ans.push_back(opt);
        return;
    }
    if (i >= n)
        return;
    // exclude
    solve(str, ans, i + 1, n, opt);
    // include
    opt.push_back(str[i]);
    solve(str, ans, i + 1, n, opt);
    opt.pop_back();
}

vector<string> subsequences(string str)
{
    vector<string> ans;
    string opt = "";
    solve(str, ans, 0, str.length(), opt);
    return ans;
}