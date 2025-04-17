class Solution
{
public:
    vector<int> Find_mxR(vector<int> &height, int n)
    {
        vector<int> mx_right(n, 0);
        mx_right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            mx_right[i] = max(mx_right[i + 1], height[i]);
        }
        return mx_right;
    }

    vector<int> Find_mxL(vector<int> &height, int n)
    {
        vector<int> mx_left(n, 0);
        mx_left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            mx_left[i] = max(mx_left[i - 1], height[i]);
        }
        return mx_left;
    }

    int trap(vector<int> &height)
    {
        int ans = 0;
        int n = height.size();

        if (n < 3)
        {
            return ans;
        }

        vector<int> mx_left;
        vector<int> mx_right;

        mx_right = Find_mxR(height, n);
        mx_left = Find_mxL(height, n);

        for (int i = 0; i < height.size(); i++)
        {

            ans += min(mx_left[i], mx_right[i]) - height[i];
        }
        return ans;
    }
};