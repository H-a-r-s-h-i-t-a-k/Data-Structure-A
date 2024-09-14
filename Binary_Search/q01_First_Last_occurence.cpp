int First_occur(vector<long long> &nums, long long target)
{
    int ans = nums.size(), s = 0, e = nums.size() - 1, mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            e = mid - 1; // left side
        }
        else if (target > nums[mid])
        {
            s = mid + 1;
        }
        else if (target < nums[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int Last_occur(vector<long long> &nums, long long target)
{
    int ans = nums.size(), s = 0, e = nums.size() - 1, mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;
            s = mid + 1; // right side
        }
        else if (target > nums[mid])
        {
            s = mid + 1;
        }
        else if (target < nums[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

class Solution
{
public:
    pair<long, long> indexes(vector<long long> v, long long x)
    {
        int i = First_occur(v, x);

        if (i == v.size() || v[i] != x)
        {
            return {-1, -1};
        }

        int j = Last_occur(v, x);

        return {i, j};
    }
};
