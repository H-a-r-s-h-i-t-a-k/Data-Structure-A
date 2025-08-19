
// 1 brute force

int calcGCD(int n, int m)
{
  for (int i = min(n, m); i > 1; i--)
  {
    if ((n % i == 0) && (m % i == 0))
    {
      return i;
    }
  }
  return 1;
  // Write your code here.
}

//2 normal
int calcGCD(int n, int m)
{
  while (n > 0 && m > 0)
  {
    if (n > m)
    {
      n = n - m;
    }
    else
    {
      m = m - n;
    }
  }
  if (n == 0)
  {
    return m;
  }
  else
  {
    return n;
  }
  // Write your code here.
}

// 3 optimise 
int calcGCD(int n, int m)
{
  while (n > 0 && m > 0)
  {
    if (n > m)
    {
      n = n % m;
    }
    else
    {
      m = m % n;
    }
  }
  if (n == 0)
  {
    return m;
  }
  else
  {
    return n;
  }
  // Write your code here.
}