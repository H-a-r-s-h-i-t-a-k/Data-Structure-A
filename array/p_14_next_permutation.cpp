#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int ind = -1, flag = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            flag = i;
            break;
        }
    }
    if (flag == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; n > flag; i--)
    {
        if (nums[i] > nums[flag])
        {
            swap(nums[i], nums[flag]);
            break;
        }
    }

    reverse(nums.begin() + flag + 1, nums.end());
}

int main()
{
    vector<int> nums = {2, 3, 4, 5, 2, 2, 1, 3, 4, 5, 6, 4, 3, 2, 2, 2, 1, 4};

    nextPermutation(nums);

    for (auto i : nums)
        cout
            << i << " ";
}