#include <iostream>
using namespace std;
#include <vector>

int getPivot(vector<int> &nums, int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (nums[mid] >= nums[0])
            s = mid + 1;
        else
            e = mid;
        mid = s + (e - s) / 2;
    }
    return s;
}
int binarySearch(vector<int> &nums, int s1, int e1, int target)
{
    int s = s1, e = e1;

    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        if (target > nums[mid])
        {
            s = mid + 1;
        }
        else
            e = mid - 1;
        mid = s + (e - s) / 2;
    }

    return -1;
}

int search(vector<int> &nums, int n, int target)
{

    int pivot = getPivot(nums, n);

    if (target >= nums[pivot] && target <= nums[n - 1])
    {
        return binarySearch(nums, pivot, n - 1, target);
    }
    else
        return binarySearch(nums, 0, pivot - 1, target);
}
int main()
{
    vector<int> nums = {7, 8, 9, 1, 2, 4, 6};
    std::cout << search(nums, nums.size(), 4);
}