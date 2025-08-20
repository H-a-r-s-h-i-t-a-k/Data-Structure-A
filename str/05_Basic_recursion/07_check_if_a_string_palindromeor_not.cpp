#include <bits/stdc++.h>
char toLower(char &ch)
{
  if (ch >= 'a' && ch <= 'z')
    return ch;

  else
  {
    char temp = ch - 'A' + 'a';
    return temp;
  }
}
bool validate(char &ch)
{
  return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}
bool checkPalindrome(string s)
{
  int st = 0;
  int e = s.size() - 1;
  while (st <= e)
  {
    while (st < e && !validate(s[st]))
    {
      st++;
    }
    while (st < e && !validate(s[e]))
    {
      e--;
    }

    if (toLower(s[st]) != toLower(s[e]))
    {
      return false;
    }
    st++;
    e--;
  }
  return true;
  // Write your code here.
}