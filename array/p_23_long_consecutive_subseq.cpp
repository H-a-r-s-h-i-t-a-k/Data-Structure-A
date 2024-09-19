#include "bits/stdc++.h"
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{

    int ans = 0;
    map<int, bool> m;

    for (int i = 0; i < N; i++)
    {
        m[arr[i]] = false;
    }

    for (int i = 0; i < N; i++)
    {
        int clen = 1;

        // traverse
        int nx = arr[i] + 1;
        while (m.find(nx) != m.end() && m[nx] == false)
        {
            clen++;
            m[nx] = true;
            nx++;
        }

        int pv = arr[i] - 1;
        while (m.find(pv) != m.end() && !m[pv])
        {
            clen++;
            m[pv] = true;
            pv--;
        }
        ans = max(clen, ans);
    }
    return ans;
    // Your code here
}
int32_t main()
{
    int N = 7, a[] = {2,
                      6,
                      1,
                      9,
                      4,
                      5,
                      3};
    cout << findLongestConseqSubseq(a, N);
}