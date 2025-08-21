
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
void reverse(vector<int> &arr, int st, int k)
{

  int s = st;
  int e = k - 1;
  while (s < e)
  {
    swap(arr[s++], arr[e--]);
  }
}

vector<int> rotateArray(vector<int> arr, int k)
{
  reverse(arr, 0, k);
  int n = arr.size();
  reverse(arr, k, n);
  reverse(arr, 0, n);
  return arr;
  // Write your code here.
}
