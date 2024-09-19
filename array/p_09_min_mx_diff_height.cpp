#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {
        1,
        3,
        5,
        5,
        6,
        6,
        7,
        6,
        5,
        4,
        1,
        -1,
        -7,
        4,
        3,
        -4,
        4,
        5,
        -5,
        -45,
        6,
        8,
        3,
        4,
        3,
        4,
        9,
    };
    int k = 2, n = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + n);
    int dif = arr[n - 1] - arr[0] + k;
    int mn = arr[0], mx = arr[n - 1];

    for (int i = 0; i < n; i++)
    {
        int cn = min(mn, arr[i - 1] - k);
        int cx = max(mx, arr[i] + k);
        if (arr[i] < 0)
            continue;
        dif = min(dif, cx - cn);
    }
    cout << dif << endl;
}