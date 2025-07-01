#include <iostream>
#include <vector> // <== This is REQUIRED for std::vector
using namespace std;
void heapify(vector<int> &arr, int i, int& size)
{
  int parent = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  int mini = i;
  if (left < size && arr[left] < arr[mini])
  {
    mini = left;
  }
  if (right < size && arr[right] < arr[mini])
  {
    mini = right;
  }
  if (mini != i)
  {
    swap(arr[mini], arr[i]);
    heapify(arr, mini, size);
  }
}
int deleteHeap(vector<int> &arr, int&  size)
{

  if (size < 1)
    return 0;

  // step1 store top and replace with last elemnt
  int ans = arr[0];
  arr[0] = arr[size - 1];
  size--;
  arr.pop_back();
  // step2 make change to top node place its position  minheap top to bottm

  heapify(arr, 0, size);
  return ans;
}
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

  int minCost(vector<int>& arr)
  {
    // code here
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(arr, i, size);
    }

    int ans = 0;
    while (size > 1)
    {
      int a = deleteHeap(arr, size);

      cout<<"first elemtn :"<<a<<endl;
      int b = deleteHeap(arr, size);
      cout << "second elemtn :" << b << endl;
      int sum = a + b;
     
      ans += sum;

      insert(arr, sum, size);
    }

    return ans;
  }
int main(){
  vector<int> ans = {4, 2, 7, 6, 9};
 
  cout<< minCost(ans)<<endl;
  return 0;
}
