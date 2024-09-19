#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findDuplicate2(vector<int> &nums)
{
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {   ans = ans ^ nums[i];
    }

    for (int i = 1; i < nums.size(); i++)
    {
        ans = ans ^ i;
    }

    return ans;
}
int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == nums[i + 1])
            return nums[i];

    return -1;
}
int main()
{
    int n = 9;
    vector<int> arr{1, 2, 3, 4, 2, 54, 566, 44, 3, 4, 4, 4446, 5, 6, 754, 4, 3, 34, 4, 5, 7, 6, 6, 5, 8};

    cout << findDuplicate(arr);
}