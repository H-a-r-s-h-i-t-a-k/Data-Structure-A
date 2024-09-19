#include <iostream>
#include <algorithm>
int main()
{
    int arr[] = {12, 2, 33, 44, 556, -8, -6, 43, -4, -24, -14, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long cr = arr[0], ms = arr[0];
    for (int i = 0; i < n; i++)
    {
        cr += arr[i];
        cr = std::max(cr, (long long)arr[i]);

        ms = std::max(ms, cr);
    }
    // for (auto i : arr)
    //     std::cout << i << " ";

    std::cout << ms;
}