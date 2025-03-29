#include <iostream>
using namespace std;
int sumarr(int arr[], int s)
{
    if (s == 0)
        return 0;
    if (s == 1)
        return arr[0];
    int sum = arr[0];
    return sum + sumarr(arr + 1, s - 1);
}
int linear(int arr[], int v, int s)
{
    if (s == 0)
        return -1;
    if (arr[0] == v)
        return 0;
    else
        return linear(arr + 1, v, s - 1);
}
int main()
{
    // int arr[] = {3, 5, 6, 7, 8, 9, 28, 34, 45, 56, 678};
    int arr[] = {1, 2, 3, 4, 5, 6};
    cout << sumarr(arr, 6);
    cout << linear(arr, 4, 6);
}