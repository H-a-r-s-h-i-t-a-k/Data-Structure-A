// brute force

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long lswrc(string s)
{
  int n = s.size();

  long long ans = LLONG_MIN;

  for (int i = 0; i < n; i++)
  {
    int hash[256] = {0};

    for (int j = i; j < n; j++)
    {
      if (hash[s[j]] == 1)
      {
        break;
      }

      hash[s[j]] = 1;
      ans = max(ans, (long long)(j - i + 1));
    }
  }

  return ans;
}

int main()
{

  string str = "";
  cin >> str;

  cout << lswrc(str) << endl;

  return 0;
}
// Better

#include <iostream>
#include <string>
#include <climits>
using namespace std;

long long LongSubString(string str)
{
  long long ans = 0;
  int hash[256] = {-1};
  int l = 0, r = 0;
  int n = str.size();
  while (r < n)
  {

    if (hash[str[r]] != -1)
    {
      if (hash[str[r]] >= l)
      {
        l = hash[str[r]] + 1;
      }
    }
    hash[str[r]] = r;

    ans = max(ans, (long long)r - l + 1);
    r++;
  }
  return ans;
}
int main()
{

  string str;
  cin >> str;

  cout << LongSubString(str) << endl;

  return 0;
}

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int ans = 0;
    int n = s.size();
    if (n <= 1)
    {
      return n;
    }
    int hash[256];
    // vector<int> hash(256,-1);
    fill(hash, hash + 256, -1);

    int l = 0, r = 0;

    while (r < n)
    {
      if (hash[s[r]] != -1)
      {
        if (hash[s[r]] >= l)
        {
          l = hash[s[r]] + 1;
        }
      }

      hash[s[r]] = r;

      ans = max(ans, r - l + 1);
      r++;
    }

    return ans;
  }
};