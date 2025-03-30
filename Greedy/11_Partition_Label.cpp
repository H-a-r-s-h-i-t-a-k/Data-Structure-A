class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.length();
        vector<int> mp(26, -1);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int value = s[i] - 'a';
            mp[value] = i;
        }

        int i = 0;
        while (i < n)
        {
            int end = mp[s[i] - 'a'];

            int j = 0;
            while (j < end)
            {
                end = max(end, mp[s[j] - 'a']);
                j++;
            }
            ans.push_back(j - i + 1);
            i = j + 1;
        }
        return ans;
    }
};