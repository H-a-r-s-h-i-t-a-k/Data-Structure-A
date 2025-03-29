class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int i, int n, vector<int> subset)
    {
        // base case
        if (i == n)
        {
            ans.push_back(subset);
            return;
        }

        // exclude
        solve(nums, ans, i + 1, n, subset);
        // include
        subset.push_back(nums[i]);
        solve(nums, ans, i + 1, n, subset);
        return;
    }
    // using backtraking optimize
    void solveB(vector<int> &nums, vector<vector<int>> &ans, int i, int n, vector<int> subset)
    {

        ans.push_back(subset);
        for (int a = i; a < nums.size(); a++)
        {

            subset.push_back(nums[a]);
            solveB(nums, ans, a + 1, n, subset);
            subset.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> ans;
        int n = nums.size();
        int i = 0;
        vector<int> subset;
        solveB(nums, ans, i, n, subset);
        // solve(nums,ans,i,n,subset);
        return ans;
    }
};