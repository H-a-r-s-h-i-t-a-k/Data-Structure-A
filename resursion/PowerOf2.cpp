#include <iostream>
#include <vector>
using namespace std;
int fun(int num)
{
    if (num == 0)
        return 1;
    return 2 * fun(num - 1);
}

int main()
{

    int num = 4;
    int ans = fun(num );

    cout << ans;
}