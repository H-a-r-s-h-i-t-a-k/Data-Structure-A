#include <iostream>
#include <set>
int main()
{
    int arr1[] = {34, 12, 45, 67, 34, 6, 723, 45}, arr2[] = {12, 34, 5, 46, 76, 5, 656, 65};
    int n = sizeof(arr1) / sizeof(arr1[0]), m = sizeof(arr2) / sizeof(arr2[0]);

    std::set<int> s;

    for (int i = 0; i < (n | m); i++)
    {
        s.insert(arr1[i]);
        s.insert(arr2[i]);
    }

    for (auto st : s)
        std::cout << st << " ";

    return 0;
}