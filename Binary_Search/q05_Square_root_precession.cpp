#include <iostream>
long long int s_rootint(int n)
{
    int s = 0, e = n;
    long long int mid = s + (e - s) / 2, ans = -1;
    while (s <= e)
    {
        long long int sq = mid * mid;
        if (sq == n)
        {
            return mid;
        }
        if (sq < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;

        mid = s + (e - s) / 2;
    }
    return ans;
}
double more_precision(int num, int intsq, int pre)
{
    double factor = 1, ans = intsq;
    for (int i = 0; i < pre; i++)
    {
        factor /= 10;
        for (double j = ans; j * j < num; j = j + factor)
        {
            ans = j;
        }
    }

    return ans;
}
int main()
{
    int num = 26;
    int int_sq = s_rootint(num);
    std::cout << more_precision(num, int_sq, 5);
}