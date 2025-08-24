class Solution
{
public:
  int search(vector<int> &arr, int x)
  {
    int index = -1;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] == x)
      {
        index = i;
        break;
        // break if we find first occurance
        //  and not break if  we find last occurance
      }
    }
    return index;
    // code here
  }
};