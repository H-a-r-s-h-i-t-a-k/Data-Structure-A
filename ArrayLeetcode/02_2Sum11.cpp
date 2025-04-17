//////////// Sorted using two pointer

class Solution
{
public:
    vector<int> solve(vector<int> &arr, int target, int n)
    {
        for (int i = 0, j = n - 1; i < n && j >= 0;)
        {
            int sum = arr[i] + arr[j];
            if (sum > target)
            {
                j--;
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                return {i + 1, j + 1};
            }
        }
        return {};
    }

    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        return solve(numbers, target, n);
    }
};