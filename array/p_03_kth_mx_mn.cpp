#include <iostream>
#include <algorithm>
// #include <functional>
void k_largest(int a[], int n, int k)
{

    sort(a, a + n, std::greater<int>());
    for (int i = 0; i < k; i++)
    {
        std::cout << a[i] << ',';
    }
}
int main()
{
    int a[] = {12, 2, 12, 34, 5, 6, 67, 45, 45, 4, 567, 98};
    int sz = sizeof(a) / sizeof(a[0]), k = 5;
    k_largest(a, sz, k);
}