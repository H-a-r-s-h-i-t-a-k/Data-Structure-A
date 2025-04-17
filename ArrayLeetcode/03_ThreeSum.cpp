class Solution
{
public:
    //  vector<vector<int>> ans;
    //   void  twosum(vector<int>&nums,int fix,int i,int  j){

    //          while(i<j){

    //                 if((nums[i]+nums[j])<fix){
    //                     i++;
    //                 }else if ((nums[i]+nums[j])>fix){
    //                     j--;
    //                 }
    //                 else {
    //                          while(i<j&&nums[i]==nums[i+1])
    //                         {
    //                             i++;
    //                         }
    //                 while(i<j&&nums[j]==nums[j-1])
    //                 {
    //                     j--;
    //                 }

    //                     ans.push_back({-fix,nums[i],nums[j]});
    //                     i++;j--;
    //                 }
    //              }

    //     }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3)
        {
            return {};
        }
        ans.clear();
        // step1    Sort the elemnt
        sort(nums.begin(), nums.end());
        // step2    fix one number then find two sum.
        for (int a = 0; a < nums.size(); a++)
        {
            if (a > 0 && nums[a] == nums[a - 1])
            {
                continue;
            }
            int fix = nums[a] * (-1);

            int i = a + 1;
            int j = n - 1;
            while (i < j)
            {

                if ((nums[i] + nums[j]) < fix)
                {
                    i++;
                }
                else if ((nums[i] + nums[j]) > fix)
                {
                    j--;
                }
                else
                {
                    while (i < j && nums[i] == nums[i + 1])
                    {
                        i++;
                    }
                    while (i < j && nums[j] == nums[j - 1])
                    {
                        j--;
                    }

                    ans.push_back({-fix, nums[i], nums[j]});
                    i++;
                    j--;
                }
            }
            // twosum(nums, fix,a+1, n-1);
        }

        return ans;
    }
};