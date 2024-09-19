#include "bits/stdc++.h"
using namespace std;
int32_t main()
{
}
string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a1[i]]++;

    for (int i = 0; i < m; i++)
    {
        if (mp[a2[i]] == 0)
            return "No";

        else
            mp[a2[i]]--;
    }
    return "Yes";
}

int32_t main()
{
    int a1[] = {11, 7, 1, 13, 21, 3, 7, 3}, a2[] = {11,
                                                    3,
                                                    7,
                                                    1,
                                                    7};
    cout << isSubset(a1, a2, 8, 5);
    return 0;
}