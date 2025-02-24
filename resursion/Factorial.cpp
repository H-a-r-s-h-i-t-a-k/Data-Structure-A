#include <iostream>
using namespace std;
int Fact(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num * Fact(num - 1);
}
int main()
{
    cout << Fact(5);
    return 0;
}