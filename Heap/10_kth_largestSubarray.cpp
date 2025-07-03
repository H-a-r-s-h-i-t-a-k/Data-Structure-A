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