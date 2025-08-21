#include <bits/stdc++.h>
void bubbleSort(vector<int> &arr, int n)
{
  for (int i = 1; i < n; i++)
  {
    int swapCount = 0;
    for (int j = 0; j < n - 1; j++)
    {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
      swapCount++;
    }
    if (swapCount == 0)
    {
      break;
    }
  }
  // Write your code here.
}
