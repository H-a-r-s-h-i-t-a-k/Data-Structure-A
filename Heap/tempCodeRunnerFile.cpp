void insert(vector<int> &arr, int val, int &size)
{
  arr.push_back(val);
  size++;
  int index = size-1;
  while (index > 0)
  {
    int parent =( index-1 )/ 2;
    if (arr[parent] > arr[index])
    {
      swap(arr[parent], arr[index]);
      index = parent;
      
    }
    else
    {
      return;
    }
  }
}