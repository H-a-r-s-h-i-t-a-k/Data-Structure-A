void pushZerosAtEnd(vector<int> &arr)
{
  int zero = INT_MIN;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      zero = i;
      break;
    }
  }
  if (zero == INT_MIN)
  {
    return;
  }

  for (int i = zero; i < n; i++)
  {
    if (arr[i] != 0)
    {
      swap(arr[i], arr[zero]);
      zero++;
    }
  }

  // Write your code here.
}