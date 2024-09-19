#include "bits/stdc++.h"
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    int mindif = INT_MAX;

    for (int i = 0; i <= n - m; i++)
    {
        int dif = a[i + m - 1] - a[i];
        if (dif < mindif)
            mindif = dif;
    }

    return mindif;
    // code
}
int32_t main()
{
    long long N = 8, M = 5;
    vector<long long> A = {3, 4, 1, 9, 56, 7, 9, 12};
    cout << findMinDiff(A, N, M);
}