#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> st;

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s == 0 || st.find(s) != st.end())
            return true;

        st.insert(s);
    }
    return false;
}
int32_t main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int n = 5;
    cout << subArrayExists(arr, n);
}
