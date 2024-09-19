#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
        ans = ans ^ nums[i];

    return ans;
}
int main()
{
    int t;
    cin >> t;
    vector<int> nums(t);
    for (int i = 0; i < t; i++)
    {
        cin >> nums[0];
    }
    cout << singleNumber(nums);
    return 0;
}