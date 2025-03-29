class Solution
{
public:
    // not optimize
    void solveB(vector<int> &nums, vector<vector<int>> &ans, int i, int n, vector<int> subset)
    {

        if (count(ans.begin(), ans.end(), subset) > 0)
        {
            return;
        }
        ans.push_back(subset);
        for (int a = i; a < n; a++)
        {

            subset.push_back(nums[a]);
            solveB(nums, ans, a + 1, n, subset);
            subset.pop_back();
        }
        return;
    }
    // optimize
    void solve(vector<int> &nums, vector<vector<int>> &ans, int i, int n, vector<int> &subset)
    {
        // base case
        if (i == n)
        {
            ans.push_back(subset);
            return;
        }
        // include
        subset.push_back(nums[i]);
        solve(nums, ans, i + 1, n, subset);
        subset.pop_back();
        int it = i + 1;
        while (it < n && nums[it] == nums[it - 1])
            it++;
        // exclude
        solve(nums, ans, it, n, subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> subset;
        //  solveB(nums,ans,0,nums.size(), subset);
        solve(nums, ans, 0, nums.size(), subset);
        return ans;
    }
};