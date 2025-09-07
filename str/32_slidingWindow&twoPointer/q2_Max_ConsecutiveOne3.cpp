class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    // brute force
    //  int ans=0,n=nums.size();
    //  int cnt=0;
    //  for(int i=0;i<n;i++){

    //     cnt=0;
    //     for(int j=i;j<n;j++){
    //         if(nums[j]==0) cnt++;
    //         if(cnt>k) break;
    //         ans=max(ans,j-i+1);
    //     }
    // }
    // return ans;

    // better

    // int l=0,r=0;
    // int ans=0,n=nums.size();
    // int cnt=0;
    // for(int r=0;r<n;r++){
    //     if(nums[r]==0){
    //         cnt++;
    //     }
    //     while(cnt>k){
    //         if(nums[l]==0)cnt--;
    //         l++;
    //     }
    //     ans=max(ans,r-l+1);

    // }

    // return ans;

    // optimize

    int l = 0, r = 0;
    int ans = 0, n = nums.size();
    int cnt = 0;
    for (int r = 0; r < n; r++)
    {
      if (nums[r] == 0)
      {
        cnt++;
      }
      if (cnt > k)
      {
        if (nums[l] == 0)
          cnt--;
        l++;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
