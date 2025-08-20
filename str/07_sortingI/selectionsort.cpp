v #include<bits / stdc++.h>

    void selectionSort(vector<int> &arr, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int res = i;
    for (int a = i + 1; a < n; a++)
    {
      if (arr[res] > arr[a])
      {
        res = a;
      }
    }
    swap(arr[res], arr[i]);
  }

  // Write your code here.
}