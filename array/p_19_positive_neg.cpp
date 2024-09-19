
#include <iostream>
#include <vector>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{
    int no = nums.size();
    vector<int> res(no, 0);
    int p = 0, n = 1;
    for (int i = 0; i < no; i++)
    {
        if (nums[i] < 0)
        {
            res[n] = nums[i];
            n += 2;
        }
        else
        {
            res[p] = nums[i];
            p += 2;
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = rearrangeArray(nums);
    for (auto i : ans)
        cout << i << " ";
}