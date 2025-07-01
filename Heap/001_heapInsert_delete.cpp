// #include <bits/stdc++.h>
// using namespace std;

// class MinHeap{

//   public:
//   int* arr;
//   int size, capacity;
//     MinHeap(int cap)
//     {
//       capacity = cap;
//       arr = new int[capacity];
//       size = 0;
//       arr[0] = -1;
//     }
//     void swap(int &num1, int &num2)
//     {
//       int temp = num1;
//       num1 = num2;
//       num2 = temp;
//     }
//     void insert( int val)
//     {
//       size = size + 1;
//       int index = size;
//       arr[index] = val;

//       while (index > 1)
//       {
//         int parent = index / 2;

//         if (arr[parent] > arr[index])
//         {

//           swap(arr[parent], arr[index]);
//           index = parent;
//         }
//         else
//         {
//           return;
//         }
//       }

//     } // insert

//     void traverse()
//     {
//       for (int i = 1; i < size + 1; i++)
//       {
//         cout << arr[i] << " ";
//       }
//       cout << endl;
//     }

//     void deleteH()
//     {
//       // underflow
//       if (size == 0)
//         return;

//       // put last value to fist
//       arr[1] = arr[size];
//       size--;

//       int i = 1;
//       while (i <= size)
//       {
//         int left = 2 * i;
//         int right = 2 * i + 1;

//         if (left<size+1&& arr[i] > arr[left])
//         {
//           swap(arr[i], arr[left]);

//           i = left;
//         }
//         else if (right<size + 1 && arr [i]> arr[right])
//         {
//           swap(arr[i], arr[right]);
//           i = right;
//         }
//         else
//         {
//           return;
//         }
//       }
//     }
// };

//   int main()
//   {
//     // your code goes here
//     int n,val;
//     cin >> n;
//     MinHeap heap = MinHeap(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//       cin >> val;
//       heap.insert( val);
//       heap.traverse();
//     }
//     for (int i = 1; i <= n; i++)
//     {
//       heap.traverse();
//       heap.deleteH();

//     }
//     return 0; // traverse heap
//   }

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{

public:
  int *arr;
  int size, capacity;
  MinHeap(int cap)
  {
    capacity = cap;
    arr = new int[capacity];
    size = 0;
    arr[0] = -1;
  }
  void swap(int &num1, int &num2)
  {
    int temp = num1;
    num1 = num2;
    num2 = temp;
  }
  void insert(int val)
  {
    if (size >= capacity - 1)
    {
      cout << "Heap Overflow\n";
      return;
    }
    size = size + 1;
    int index = size;
    arr[index] = val;

    while (index > 1)
    {
      int parent = index / 2;

      if (arr[parent] < arr[index])
      {

        swap(arr[parent], arr[index]);
        index = parent;
      }
      else
      {
        break;
      }
    }

  } // insert

  int top()
  {
    return size == 0 ? -1 : arr[1];
  }

  void traverse()
  {
    for (int i = 1; i < size + 1; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void deleteH()
  {
    // underflow
    if (size == 0)
      return;

    // put last value to fist
    arr[1] = arr[size];
    size--;

    int i = 1;
    while (i <= size)
    {
      int p = i;
      int left = 2 * i;
      int right = 2 * i + 1;

      if (left < size + 1 && arr[i] < arr[left])
      {

        p = left;
      }
      if (right < size + 1 && arr[i] < arr[right])
      {
        p = right;
      }
      if (p != i)
      {
        swap(arr[i], arr[p]);
      }
      else
      {
        break;
      }
    }
  }
};

int main()
{
  // your code goes here
  int n, val;
  cin >> n;
  MinHeap heap(n + 1);
  while (n--)
  {
    string op;
    cin >> op;

    if (op == "-")
    {
      heap.deleteH();
      cout << heap.top() << endl;
    }
    else
    {
      cin >> val;
      heap.insert(val);
      cout << heap.top() << endl;
    }
  }

  return 0; // traverse heap
}

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
  int *arr;
  int size;
  int capacity;

  MinHeap(int cap)
  {
    arr = new int[cap];
    capacity = cap;
    size = 0;
    arr[0] = -1;
  }
  void swap(int &num1, int &num2)
  {
    int temp = num1;
    num1 = num2;
    num2 = temp;
  }
  void insert(int val)
  {
    size++;
    int index = size;
    arr[index] = val;

    int parent = index / 2;
    while (index > 1)
    {
      if (arr[parent] > arr[index])
      {
        int temp = arr[parent];
        arr[parent] = arr[index];
        arr[index] = temp;

        index = parent;
      }
      else
      {
        return;
      }
    }
  } // insert

  void deleteH()
  {
    // underflow
    if (size == 0)
      return;

    // put last value to fist
    arr[1] = arr[size];
    size--;

    int i = 1;
    while (i <= size)
    {
      int left = 2 * i;
      int right = 2 * i + 1;

      if (left < size + 1 && arr[i] > arr[left])
      {
        swap(arr[i], arr[left]);

        i = left;
      }
      else if (right < size + 1 && arr[i] > arr[right])
      {
        swap(arr[i], arr[right]);
        i = right;
      }
      else
      {
        return;
      }
    }
  }

  void traverse()
  {
    for (int i = 1; i < size + 1; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};
int main()
{
  // your code goes here

  int n, val;
  cin >> n;

  MinHeap heap = MinHeap(n + 1);
  int i = 1;
  while (i < n + 1)
  {
    cin >> val;
    heap.arr[i] = val;
    i++;
  }
  heap.size = n;
  int j = n;

  while (j--)
  {
    heap.deleteH();
    heap.traverse();
  }
  return 0;
}