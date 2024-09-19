#include <iostream>
void reverse(int arr[], int s)
{
    int st = 0, end = s - 1;
    while (st < end)
    {
        int t1 = arr[st];
        arr[st] = arr[end];
        arr[end] = t1;
        st++;
        end--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int sz = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, sz);

    for (int i = 0; i < sz; i++)
    {
        std::cout << arr[i] << " ";
    }
}