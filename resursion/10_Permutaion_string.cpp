class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int i, int n)
    {

        if (i >= n)
        {
            ans.push_back(nums);
            return;
        }
        for (int a = i; a < nums.size(); a++)
        {
            swap(nums[i], nums[a]);
            solve(nums, ans, i + 1, n);
            swap(nums[i], nums[a]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        solve(nums, ans, 0, nums.size());
        return ans;
    }
};