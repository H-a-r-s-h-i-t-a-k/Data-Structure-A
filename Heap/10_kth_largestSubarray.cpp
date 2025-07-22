// User function Template for C++

class Solution
{
public:
  int kthLargest(vector<int> &arr, int k)
  {
    // code here

    // step1 create a min heap of length k
    // step2 push first k no of sum
    // step3 then compare heap.top() to new sum and pop(), push new sum
    // step4 do step 3 till heap.size() =1
    // step5 return the ans as heap top()
    //////////////////////////////////////////////////////////////////
    // step1 create a min heap of length k
    priority_queue<int, vector<int>, greater<int>> minheap;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = i; j < n; j++)
      {
        sum += arr[j];

        // step2 push first k no of sum
        if (minheap.size() < k)
        {
          minheap.push(sum);
        }
        // step3 then compare heap.top() to new sum and pop(), push new sum
        else if (sum > minheap.top())
        {
          minheap.pop();
          minheap.push(sum);
        }
      }
    }

    return minheap.top();
    // step5 return the ans as heap top()
  }
};



///////////////////////////////////////

class heap
{
public:
  int *arr;
  int size;
  int capacity;

  heap(int capacity)
  {
    arr = new int[capacity + 1];
    this->capacity = capacity;
    size = 0;
    arr[0] = -1;
  }
  void insertheap(int value)
  {
    if (size >= capacity)
    {
      return;
    }

    int index = ++size;
    arr[size] = value;

    while (index > 1)
    {
      int parent = index / 2;
      if (arr[parent] > arr[index])
      {
        swap(arr[parent], arr[index]);
        index = parent;
      }
      else
      {
        break;
      }
    }
  }
  /////////
  int getTop()
  {
    return arr[1];
  }
  void deleteheap()
  {
    if (size == 0)
    {
      return;
    }
    arr[1] = arr[size];
    size--;

    int i = 1;
    while (1)
    {
      int itr = i;
      int left = 2 * i;
      int right = 2 * i + 1;

      if (left < size + 1 && arr[i] > arr[left])
      {
        i = left;
      }
      if (right < size + 1 && arr[i] > arr[right])
      {
        i = right;
      }
      if (i != itr)
      {
        swap(arr[i], arr[itr]);
      }
      else
      {
        break;
      }
    }
  }
};

class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    heap *minheap = new heap(k);

    for (int i = 0; i < nums.size(); i++)
    {
      if (minheap->size < k)
      {
        minheap->insertheap(nums[i]);
      }
      else
      {
        int front = minheap->arr[1];
        if (front <= nums[i])
        {
          minheap->deleteheap();
          minheap->insertheap(nums[i]);
        }
      }
    }
    return minheap->arr[1];
  }
};