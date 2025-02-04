#include <iostream>
using namespace std;
#define ll long long
int main()
{
    ll l, n, arr[1000];
    cin >> l;
    while (l--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        if (arr[1] <= n + 1)
            cout << "NO" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}