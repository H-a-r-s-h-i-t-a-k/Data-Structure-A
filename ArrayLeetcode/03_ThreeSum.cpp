#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    vector<vector<int>> ans;
    if (n < 3)
        return ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int tar = K - arr[i];

        int s = i + 1, e = n - 1;

        while (s < e)
        {
            int value = arr[s] + arr[e];
            // cout<<
            if (value == tar)
            {

                while (s < e && arr[s] == arr[s + 1])
                {
                    s++;
                }
                while (s < e && arr[e] == arr[e + 1])
                {
                    e--;
                }
                ans.push_back({arr[i], arr[s], arr[e]});
                s++;
                e--;
            }
            else if (value < tar)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
    }
    return ans;
}