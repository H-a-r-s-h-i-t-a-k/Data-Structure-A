#include "bits/stdc++.h"
using namespace std;
long long trappingWater(int arr[], int n)
{
    int l[n], r[n];
    l[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        l[i] = max(l[i - 1], arr[i]);
    }
    r[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = max(r[i + 1], arr[i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(l[i], r[i]) - arr[i]);
    }
    return ans;
    // code here
}
int32_t main()
{
    int N = 6, arr[] = {3,
                        0,
                        0,
                        2,
                        0,
                        4};

    cout << trappingWater(arr, N);
}