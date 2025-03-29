#include <iostream>
#include <vector>
using namespace std;
int fun(int num)
{
    if (num == 0)
        return 1;
    return 2 * fun(num - 1);
}

int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int ans = power(a, b / 2);
    if (b & 1)
    {
        return a * ans * ans;
    }
    return ans * ans;
}

int main()
{

    int num = 4;
    int ans = fun(num);

    cout << ans;
    cout << power(3, 3);
}