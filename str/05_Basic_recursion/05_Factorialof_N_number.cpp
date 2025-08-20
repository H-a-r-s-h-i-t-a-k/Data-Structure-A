#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

string multiply(string one, int two)
{
  string ans = "";
  int carry = 0;
  int cnt = one.size() - 1;
  while (cnt >= 0)
  {
    int mul = (one[cnt] - '0') * two + carry;
    ans.push_back(mul % 10 + '0');
    carry = mul / 10;

    cnt--;
  }
  while (carry > 0)
  {
    int last = carry % 10;
    ans.push_back(last + '0');
    carry /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

// long long solve(long long n){
//     if(n==1){
//         return 1;
//     }
//     return n*solve(n-1);
// }

void factorial(int n)

{
  vector<string> ans(n + 1);
  ans[0] = "1";
  ans[1] = "1";
  if (n <= 1)
  {
    cout << "1";
    return;
  }

  for (int i = 2; i <= n; i++)
  {
    ans[i] = multiply(ans[i - 1], i);
  }
  cout << ans[n];
  // Write your code here
}
