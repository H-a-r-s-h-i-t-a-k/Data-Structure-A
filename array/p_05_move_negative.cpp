#include <iostream>
#include <algorithm>
int main()
{
    int arr[] = {2, 3, 1, 1, 2, -1, -3, -5, 65, 678};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}
