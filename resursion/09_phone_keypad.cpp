class Solution
{
public:
    void solve(string digits, vector<string> &ans, int i, string out, vector<string> phone)
    {
        if (i >= digits.length())
        {
            if (out.length() > 0)
                ans.push_back(out);
            return;
        }
        int num = digits[i] - '0';
        string value = phone[num];
        for (int a = 0; a < value.length(); a++)
        {
            out.push_back(value[a]);
            solve(digits, ans, i + 1, out, phone);
            out.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string out = "";
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, ans, 0, out, phone);
        return ans;
    }
};