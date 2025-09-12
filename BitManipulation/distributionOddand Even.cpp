class Solution
{
public:
  bool isvowel(char ch)
  {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
      return true;
    }
    return false;
  }
  bool alice(string s, int &l, int &r, int n)
  {

    // vector<int >substring(26,0);
    int cnt = 0;
    // int maxlen=0;
    while (r < n)
    {
      int ch = s[r] - 'a';
      if (isvowel(s[r]))
      {
        // substring[ch]++;

        cnt++;
      }
      r++;
    }
    while ((cnt & 1) == 0 && cnt != 0 && l < r)
    {
      // even
      if (isvowel(s[r]))
      {
        cnt--;
      }
      if (cnt == 0)
      {
        return false;
      }
      r--;
    }
    // maxlen=r-l+1;
    // if(cnt==0)return true;
    return (cnt & 1);
  }
  bool bob(string s, int &l, int &r, int n)
  {
    if (!isvowel(s[r]))
    {
      r++;
      return true;
    }
    int cnt = 1;
    r++;
    while (r < n)
    {
      if (isvowel(s[r]))
      {
        r++;
        return true;
      }
      r++;
    }
    return false;
  }
  bool doesAliceWin(string s)
  {
    int turn = 1;
    int l = 0, r = 0;
    bool ansa = false;
    bool ansb = false;
    int n = s.size();
    while (r < n)
    {
      if (turn)
      {
        ansa = alice(s, l, r, n);
        l = r;
        turn = 0;
      }
      else
      {
        ansb = bob(s, l, r, n);
        turn = 1;
        l = r;
      }
    }

    if (ansa && ansb)
    {
      return true;
    }
    else if (!ansa)
    {
      return false;
    }
    else if (!ansb)
    {
      return true;
    }
    return false;
  }
};