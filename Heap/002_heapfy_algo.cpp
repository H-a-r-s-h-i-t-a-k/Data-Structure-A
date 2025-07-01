#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[] , int i, int size)
{
  

  int p = i;
  int left = 2 * i +1;
  int right = 2 * i + 2;

 
    if (left< size && arr[p] < arr[left])
    {
      p = left;
    }
    if (right < size && arr[p] < arr[right])
    {
      p = right;
    }
    if (p != i)
    {
      swap(arr[p], arr[i]);
      heapify(arr, p, size);
    }
    
 
}

void heapsort(int arr[],int size)
{
  // step1 build heap 
  for (int i = size / 2  -1; i >=0; i--)
  {
    heapify(arr, i, size);
  }
// step2 Alter

  for(int n=size-1; n>=0;n--)
  { swap(arr[n],arr[0]);
   
    heapify(arr, 0, n );
  }
}
int main()
{

  int arr[] = {5, 2, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  cout<<endl;

 heapsort(arr,n);

 cout << endl;
 for (int i = 0; i < n; i++)
 {
   cout << arr[i] << " ";
 }



return 0;
  // your code goes here
}
