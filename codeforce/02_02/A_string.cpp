#include <iostream>
#include <string>
using namespace std;
int solve(string num)
{
    int ans = 0;
    for (int i = 0; num[i] != '\0'; i++)
    {
        if (num[i] == '1')
            ans++;
    }

    return ans;
}
int main()
{
    int n;
    string num;
    cin >> n;
    while (n)
    {
        cin >> num;
        cout << solve(num) << endl;
        n--;
    }
    return 0;
}