// User function Template for C++

class Solution
{

  void heapify(vector<int> &arr, int i, int size)
  {
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int larg = i;
    if (left < size && arr[larg] < arr[left])
      larg = left;
    if (right < size && arr[larg] < arr[right])
      larg = right;

    if (larg != i)
    {
      swap(arr[larg], arr[i]);
      heapify(arr, larg, size);
    }
  }
  void heapsort(vector<int> &arr, int &size)
  {
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(arr, i, size);
    }
    //   for(int n=size-1;n>0;n--){
    //       swap(arr[n],arr[0]);
    //       heapify(arr,0,n);
    //   }
  }

public:
  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
  {
    // your code here

    vector<int> merged;
    for (int num : a)
    {
      merged.push_back(num);
    }
    for (int num : b)
    {
      merged.push_back(num);
    }
    int size = merged.size();
    heapsort(merged, size);

    return merged;
  }
};