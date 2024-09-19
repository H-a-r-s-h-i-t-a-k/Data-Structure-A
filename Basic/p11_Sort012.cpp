#include <iostream>
#include <algorithm>

void sort012(int a[], int l)
{
    int I = 0, II = 0, III = l - 1;
    int temp;
    while (II <= III)
    {
        switch (a[II])
        {
        case 0:
            std::swap(a[I++], a[II++]);

            break;
        case 1:
            II++;
            break;
        case 2:
            std::swap(a[II], a[III--]);
            break;
        }
    }
}
int main()
{
    int ar[] = {0, 1, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0};
    int sr = sizeof(ar) / sizeof(ar[0]);
    // std::sort(ar, ar + sr);
    sort012(ar, sr);
    for (int i = 0; i < sr; i++)
        std::cout << ar[i];
}