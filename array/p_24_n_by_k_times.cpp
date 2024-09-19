#include "bits/stdc++.h"
using namespace std;

int countOccurence(int arr[], int n, int k)
{
    int o = n / k, count = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto i : mp)
    {
        if (i.second > o)
        {
            count++;
        }
    }
    return count;

    // Your code here
}
int32_t main()
{
    int N = 8, arr[] = {3, 1, 2, 2, 1, 2, 3, 3}, k = 4;
    cout << countOccurence(arr, N, k);
}