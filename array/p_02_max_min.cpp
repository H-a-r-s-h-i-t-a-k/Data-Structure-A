#include <iostream>

void min_mx(int a[], int sz)
{
    int min = a[0], mx = -1;
    for (int i = 0; i < sz; i++)
    {
        if (a[i] < min)
            min = a[i];

        if (a[i] > mx)
            mx = a[i];
    }

    std::cout << "min " << min << "max:" << mx;
}
int main()
{
    int arr[] = {1, 4, 2, 3, 6, 9, 85, 5, 4, 8};
    int s = sizeof(arr) / sizeof(arr[0]);
    min_mx(arr, s);
    // for (int i = 0; i < s; i++)
    // {
    //     std::cout << arr[i] << "  ";
    // }
}