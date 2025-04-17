class Solution
{
public:
  int countDer(int n)
  {
    if (n == 1)
      return 0;
    if (n == 2)
      return 1;
    // return (n-1) * (countDer(n-1)+countDer(n-2));
    int prev1 = 0;
    int prev2 = 1;
    for (int i = 3; i <= n; i++)
    {
      int curr = (i - 1) * (prev1 + prev2);
      prev1 = prev2;
      prev2 = curr;
    }

    return prev2;
  }
};