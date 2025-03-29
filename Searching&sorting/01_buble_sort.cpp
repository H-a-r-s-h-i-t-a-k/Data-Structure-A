#include <iostream>
using namespace std;
void buble(int arr[], int s)
{
    if (s == 0 || s == 1)
        return;
    if (arr[0] > arr[1])
        swap(arr[0], arr[1]);

    return buble(arr + 1, s - 1);
}
void sortarr(int arr[], int num)
{
    while (num)
    {
        buble(arr, num);
        num--;
    }
}
int main()
{
    int arr[] = {134, 23, 3456, 344, 5673, 32, 21};
    int num = 7;
    sortarr(arr, num);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 1;
}