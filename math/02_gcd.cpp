#include <iostream>
#include<vector>
using namespace std;

// lcm(a,b)*gcd(a,b)=a*b
// gcd(n,m){ gcd(m%n,m)
// gcd(n,m)=gcd(m-n,m)=gcd(0,a)=a

// int gcd(int n, int m)
// {
//     if (n == 0)
//     {
//         return m;
//     }
//     if (m == 0)
//     {
//         return n;
//     }
//     while (n != m)
//     {
//         if (n > m)
//         {
//             n = n - m;
//         }
//         else
//             m = m - n;
//     }
//     return n;
// }
int main()
{  vector<vector<string>> ans;
    ans.push_back({{"0"}});
    cout<<ans[0][0];
    // cout << gcd(6, 2);
    return 0;
}