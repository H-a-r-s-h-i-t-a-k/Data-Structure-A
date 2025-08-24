class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    //      int n=nums.size();
    // int limit=n/2;
    // for(int i=0;i<n;i++){
    //     int cnt=0;
    //     for( int j=0;j<n;j++){
    //         if(nums[i]==nums[j]){
    //             cnt++;
    //         }
    //     }
    //     if(cnt>limit){

    //        return nums[i];

    //     }

    // }
    // return -1;
    // }

    // app2

    int cnt = 0, n = nums.size();
    int element = -1;
    for (int i = 0; i <= n - 1; i++)
    {
      if (cnt == 0)
      {
        cnt = 1;
        element = nums[i];
      }
      else if (nums[i] == element)
      {
        cnt++;
      }
      else
      {
        cnt--;
      }
    }
    return element;
  }
};