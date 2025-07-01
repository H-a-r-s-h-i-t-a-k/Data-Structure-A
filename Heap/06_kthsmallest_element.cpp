class Solution
{
public:
  // arr : given array
  // k : find kth smallest element and return using this function
  int kthSmallest(vector<int> &arr, int k)
  {
    // code here

    // step 1 build max heap of first element
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
      pq.push(arr[i]);
    }
    // step 2 compare each element range k to end of array with top of heap

    for (int i = k; i < arr.size(); i++)
    {

      // if found greater element then pop, push
      if (arr[i] < pq.top())
      {
        pq.pop();
        pq.push(arr[i]);
      }
    }
    // step 3 at the end of step2 return the element
    return pq.top();
  }
};