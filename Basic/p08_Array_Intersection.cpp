#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> intersectionUnsorted_array(vector<int> &nums1, vector<int> &nums2)
{
    set<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {

            ans.insert(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    vector<int> vc(ans.begin(), ans.end());
   
    return vc;
}
int main()
{
    int t;
    cin >> t;
    vector<int> nums1(t), nums2(t);
    for (int i = 0; i < t; i++)
    {
        cin >> nums1[i] >> nums2[i];
    }
    vector<int> ans = intersectionUnsorted_array(nums1, nums2);
    for (int i : ans)
    {
        cout << i << "  ";
    }
    cout << endl;

    return 0;
}