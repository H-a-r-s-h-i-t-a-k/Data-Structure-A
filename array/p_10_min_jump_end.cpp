#include <iostream>
#include <utility>
int min_jump(int arr[], int n)
{

    int tjump = 0, ljump = 0, cov = 0;

    if (n <= 1)
        return 0;

    if (n == 0)
        return -1;




    

    for (int i = 0; i < n; i++)
    {
        cov = std::max(cov, i + arr[i]);

        if (ljump == i)
        {
            ljump = cov;
            tjump++;

            if (cov >= n - 1)
            {
                return tjump;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 1, 5, 2, 1, 21, 1, 45,67,78,89,23,45,12,56,23,23, 4, 5, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << min_jump(arr, n);
}
