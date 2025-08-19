int *printDivisors(int n, int &size)
{
  vector<int> fact;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      fact.push_back(i);
      int d = n / i;
      if ((d) != i)
      {
        fact.push_back(d);
      }
    }
  }
  size = fact.size();
  int *arr = new int[size];
  sort(fact.begin(), fact.end());
  // int i=0;
  for (int i = 0; i < size; i++)
  {
    arr[i] = fact[i];
  }
  return arr;
  // Write your code here
}