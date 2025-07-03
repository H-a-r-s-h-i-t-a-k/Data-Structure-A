class element
{
public:
  int val;
  int arrN;
  int indexN;

  element(int data, int an, int in)
  {
    val = data;
    arrN = an;
    indexN = in;
  }
};

class compare
{
public:
  bool operator()(element *a, element *b)
  {
    return a->val > b->val;
  }
};
class Solution
{
public:
  // Function to merge k sorted arrays.
  vector<int> mergeKArrays(vector<vector<int>> arr, int K)
  {
    // code here
    // step1 create k length of minheap
    // step2 heap consists of first element of every arr
    // step3 to record the element comes form which arrN,what indexN and val
    // create user defined class named element
    // step4 insert min heap .top() to ans vector  and store ans pop() topelement
    // ans push next element of poped array
    // step5 continue step4 till heap empty
    // step6 return the ans vector

    // step1 create k length of minheap
    // step2 heap consists of first element of every arr
    // step3 to record the element comes form which arrN,what indexN and val
    // create user defined class named element
    // step4 insert min heap .top() to ans vector  and store ans pop() topelement
    // ans push next element of poped array
    // step5 continue step4 till heap empty
    // step6 return the ans vector

    vector<int> ans;
    priority_queue<element *, vector<element *>, compare> minheap;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      minheap.push(new element(arr[i][0], i, 0));
    }

    while (!minheap.empty())
    {
      element *front = minheap.top();
      minheap.pop();
      ans.push_back(front->val);
      int i = front->arrN;
      int j = front->indexN;

      if (j + 1 < arr[i].size())
      {

        element *next = new element(arr[i][j + 1], i, j + 1);
        minheap.push(next);
      }
    }

    return ans;
  }
};