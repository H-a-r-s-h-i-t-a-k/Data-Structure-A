#include <iostream>
using namespace std;
#define ll long long

ll t, a[100], n, ans = 0;
int main()
{
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ans += a[i];
        }
        if (n == 1)
        {
            cout << a[0] << endl;
            continue;
        }
        while (n)
        {
            n--;
            ll sum = 0;
            for (int i = 1; i <= n; i++)
            {
                a[i] = a[i + 1] - a[i];
            }
            for (int j = 1; j <= n; j++)
            {
                sum += a[j];
            }
            ans = max(ans, max(sum, -sum));
        }

        cout << ans << endl;
    }
    return 0;
}
///
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// ll t, n, m, a[100];
// int main()
// {
//     scanf("%lld", &t);
//     while (t--)
//     {
//         scanf("%lld", &n);
//         ll ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             scanf("%lld", &a[i]);
//             ans += a[i];
//         }
//         if (n == 1)
//         {
//             printf("%lld\n", ans);
//             continue;
//         }
//         while (n)
//         {
//             n--;
//             for (int i = 1; i <= n; i++)
//             {
//                 a[i] = a[i + 1] - a[i];
//             }
//             ll sum = 0;
//             for (int i = 1; i <= n; i++)
//                 sum += a[i];
//             ans = max(ans, max(sum, -sum));
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }