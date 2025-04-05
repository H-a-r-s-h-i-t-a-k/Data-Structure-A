class Solution
{
public:
    int countbit(int num)
    {
        int res = 0;
        while (num > 0)
        {
            int i = num & 1; // last bit
            if (i)
                res++;
            num = num >> 1;
        }
        return res;
    }

    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            int elel = countbit(i);
            ans.push_back(elel);
        }
        return ans;
    }
};
///////////////////////////optimize
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        if (n == 0)
        {
            return ans;
        }

        ans[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((i % 2) != 0)
            {
                ans[i] = ans[i / 2] + 1;
            }
            else
            {
                ans[i] = ans[i / 2];
            }
        }

        return ans;
    }
};
