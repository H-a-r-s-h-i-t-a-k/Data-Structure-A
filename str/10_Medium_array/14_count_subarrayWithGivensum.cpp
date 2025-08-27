class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    // app1
    // int sum=0;
    // int n=nums.size();
    // int target=k;
    // int cnt=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         sum=0;
    //         for(int ko=i;ko<=j;ko++){
    //             sum+=nums[ko];
    //             }
    //             if(sum==target){
    //                 cnt++;
    //         }
    //     }
    // }
    // return cnt;

    // app2
    // int n=nums.size();
    // int cnt=0;
    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=nums[j];

    //     if(sum==k){
    //         cnt++;
    //     }
    //     }
    // }

    // return cnt;

    // app3
    unordered_map<int, int> map;
    int cnt = 0;
    map[0] = 1;
    int n = nums.size();
    int prefixsum = 0;
    for (int i = 0; i < n; i++)
    {
      prefixsum += nums[i];

      int rem = prefixsum - k;
      if (map.find(rem) != map.end())
      {

        cnt += map[rem];
      }
      map[prefixsum]++;
    }

    return cnt;

    // ans
  }
};