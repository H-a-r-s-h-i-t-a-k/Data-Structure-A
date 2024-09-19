#include <iostream>
int main()
{
    int arr[] = {1, 23, 44, 554, 56, 56, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp = arr[n - 1];
    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    for (int a : arr)
        std::cout << a << " ";

    return 0;
}