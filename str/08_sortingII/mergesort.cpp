

void merge(vector<int> &arr, int low, int mid, int high)
{
  int left = low;
  int right = mid + 1;
  vector<int> temp;
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left++]);
    }
    else
    {
      temp.push_back(arr[right++]);
    }
  }
  while (left <= mid)
  {
    temp.push_back(arr[left++]);
  }
  while (right <= high)
  {
    temp.push_back(arr[right++]);
  }
  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}

void mergeS(vector<int> &arr, int low, int high)
{
  if (low >= high)
    return;
  int mid = low + (high - low) / 2;
  mergeS(arr, low, mid);
  mergeS(arr, mid + 1, high);

  merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n)
{
  mergeS(arr, 0, n - 1);
  // Write your code here.
}