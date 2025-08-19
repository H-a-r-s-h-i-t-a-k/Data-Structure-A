#include <iostream>
#include <algorithm>
int main()
{
    int arr[] = {12, 2, 33, 44, 556, -8, -6, 43, -4, -24, -14, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long cr = arr[0], ms = arr[0];
    for (int i = 0; i < n; i++)
    {
        cr += arr[i];
        cr = std::max(cr, (long long)arr[i]);

        ms = std::max(ms, cr);
    }
    // for (auto i : arr)
    //     std::cout << i << " ";

    std::cout << ms;
}
class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        int maxsum = arr[0], curr = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (curr < 0)
            {
                curr = 0;
            }
            curr += arr[i];
            if (maxsum < curr)
            {
                maxsum = curr;
            }
        }
        return maxsum;
        // Code here
    }
};