#include <iostream>
using namespace std;
void reverse(int arr[], int s)
{

    if (s > 11 - s - 1)
        return;
    swap(arr[s], arr[11 - s - 1]);
    return reverse(arr, s + 1);
}
bool palindrome(int arr[], int s)
{

    if (s > 7 - s - 1)
        return true;
    if (arr[s] == arr[7 - s - 1])
        return palindrome(arr, s + 1);
    else
        return false;
}
int main()
{
    // int arr[] = {3, 5, 6, 7, 8, 9, 28, 34, 45, 56, 678};
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    // reverse(arr, 0);
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    cout << palindrome(arr, 0);
    return 1;
}