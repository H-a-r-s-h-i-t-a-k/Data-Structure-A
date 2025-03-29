#include <iostream>
using namespace std;
int binary(int arr[], int v, int s, int e)
{
    if (s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if (arr[mid] == v)
    {
        return mid;
    }
    else if (arr[mid] < v)
        return binary(arr, v, mid + 1, e);
    else
        return binary(arr, v, s, mid - 1);
}
bool is_sorted(int arr[], int s)
{
    if (s == 0 || s == 1)
        return true;
    if (arr[0] > arr[1])
        return false;

    else
        return is_sorted(arr + 1, s - 1);
}
int main()
{
    int arr[] = {3, 5, 6, 7, 8, 9, 28, 34, 45, 56, 678};
    cout << binary(arr, 8, 0, 10) << "  ";
    cout << is_sorted(arr, 11);
}