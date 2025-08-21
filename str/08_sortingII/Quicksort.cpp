#include <bits/stdc++.h>

int partition(vector<int> &arr, int low, int high)
{

  int i = low, j = high;
  int pivot = arr[low];
  int c = 0;
  for (int x = i + 1; x <= j; x++)
  {
    if (arr[x] <= pivot)
    {
      c++;
    }
  }

  int pivotI = low + c;

  swap(arr[low], arr[pivotI]);
  pivot = arr[pivotI];

  while (i < pivotI && j > pivotI)
  {
    while (arr[i] <= pivot)
    {
      i++;
    }
    while (arr[j] > pivot)
    {
      j--;
    }
    if (i < pivotI && pivotI < j)
    {
      swap(arr[i++], arr[j--]);
    }
  }

  return pivotI;
}

void quick(vector<int> &arr, int low, int high)
{
  if (low >= high)
  {
    return;
  }
  int pindex = partition(arr, low, high);

  quick(arr, low, pindex - 1);
  quick(arr, pindex + 1, high);
}
vector<int> quickSort(vector<int> arr)
{
  quick(arr, 0, arr.size() - 1);
  return arr;
  // Write your code here.
}
